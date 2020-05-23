function Initialize()
	ipIndex = 1
	BTdevices = {}
end

function Update()
	if tonumber(SKIN:GetVariable('freq')) > 0 then
		return #BTdevices + 1
	else
		return ipIndex
	end
end

function stepIP()
	ipIndex = ipIndex + 1
	if ipIndex <= #network then
		SKIN:Bang('!setVariable', 'deviceIP', network[ipIndex][1])
		SKIN:Bang('!updateMeasure', 'resolveName')
		SKIN:Bang('!commandMeasure', 'resolveName', 'run')
	else 
		--[[
		print('all device names have been resolved')
		displayIPs()
		]]--
		setHostString()
	end
end

function displayAdapters()
	for i, v in ipairs(adapter) do
		print(i .. 'name = ' .. v[1])
		print(i .. 'adapter = ' .. v[2])
		print(i .. 'address = ' .. v[3])
		print(i .. 'status = ' .. v[4])
	end
end

function displayIPs()
	print('Found ' .. #network .. ' devices')
	for i, v in ipairs(network) do
		if #v < 3 then
			print(v[1] .. ' = ' .. v[2])
		else	
			print(v[1] .. '(' .. v[3] .. ') = ' .. v[2])
		end
	end
end

function isDuplicate(str)
	if #network < 1 then return false else
		for i, v in ipairs(network) do
			if v[1]:match('^'.. str .. '$') ~= nil then return true end
		end
	end
	return false
end

function insertionSort(str)
	if #network < 1 then return nil else
		local numb = tonumber(str:sub(str:match(".*%.()")))
		for i, v in ipairs(network) do
			local test = tonumber(v[1]:sub(str:match(".*%.()")))
			if numb < test then	return i end
		end
	end
	return nil
end

function saveNameNslookup() --when using "nslookup [IPaddress]"
	local i = ipIndex
	local output = SKIN:GetMeasure('resolveName'):GetStringValue()
	local myIP = SKIN:GetMeasure('PCaddress'):GetStringValue()
	local myHostName = SKIN:GetMeasure('PCname'):GetStringValue()
	local name
	local server
    local serverAddress
	local found = false
	for line in output:gmatch('[^\n]+') do
		if line:match('Name') then
			name = line:sub(line:find("%:    ") + 5)
			found = true
		elseif line:match('Server') ~= nil then
			server = line:sub(line:find("%:  ") + 3)
        elseif line:match('Address') ~= nil then 
            serverAddress = line:sub(line:find('%:  ') + 3)
		end	
	end
	if network[i][1]:match(serverAddress) ~= nil then
		table.insert(network[i], server)
	elseif found == true then
		if name:find('%.') ~= nil then
			name = name:sub(1, name:match(".*%.()") - 2)
			table.insert(network[i], name)
		end
	else --name not found
		table.insert(network[i], 'Unknown')
	end
	SKIN:Bang('!UpdateMeasure', 'connectivityInfo')
	if i < #network then 
		if network[i + 1][1]:match('^' .. myIP .. '$') ~= nil then
		SKIN:Bang('!UpdateMeasure', 'connectivityInfo')
		table.insert(network[i + 1], myHostName)
		end
	end
	stepIP()

end

function getIPaddresses()
	local str = SKIN:GetMeasure('IPlist'):GetStringValue()
	network = {}
	for line in str:gmatch('[^\n]*') do
		if line:match('dynamic') ~= nil then
			local ip = line:match('%d+%.%d+%.%d+%.%d+')
			local mac = string.upper(line:match('%x+%-%x+%-%x+%-%x+%-%x+%-%x+'))
			if isDuplicate(ip) == false then
				local i = insertionSort(ip)
				if i == nil then
					table.insert(network, {} )
					i = #network
				else
					table.insert(network, i, {} )
				end
				table.insert(network[i], ip )
				table.insert(network[i], mac)
			end
		end
	end
	--[[
	displayIPs()
	]]--
-- print('Found ' .. #network .. ' network devices')
	setIPandMacStrings()
	SKIN:Bang('!setVariable', 'deviceIP', network[1][1])
	SKIN:Bang('!updateMeasure', 'resolveName')
	SKIN:Bang('!commandMeasure', 'resolveName', 'run')
end

function parseGetMac()
	local output = SKIN:GetMeasure('MacList'):GetStringValue()
	adapter = { }
	for line in output:gmatch('[^\n]+') do
		if line:find('Connection Name:') ~= nil then
			table.insert(adapter, {})
			table.insert(adapter[#adapter], line:sub(line:find(':  ') + 3) )
		elseif line:find('Network Adapter:') ~= nil then
			if line:find('Bluetooth') ~= nil then 
				if ParseBTdevices() == false then
					SKIN:Bang('!commandMeasure', 'getBTDevices', 'run')
				end
			end
			table.insert(adapter[#adapter], line:sub(line:find(':  ') + 3) )
		elseif line:find('Physical Address:') ~= nil then
			table.insert(adapter[#adapter], line:sub(line:find(': ') + 2) )
		elseif line:find('Transport Name:') ~= nil then
			local status = line:sub(line:find(': ') + 4)
			if status:match('Media disconnected') == nil then
				status = "connected"
			else status = "disconnected" end
			table.insert(adapter[#adapter], status )
		end
	end
	--displayAdapters()
end

function setIPandMacStrings()
	local ipList = network[1][1]
	local macList = network[1][2]
	for i, v in ipairs(network) do
		if i > 1 then
			ipList = ipList .. "#CRLF#" .. v[1]
			macList = macList .. "#CRLF#" .. v[2]
		end
	end
	SKIN:Bang('!Setoption', 'ipListString', 'string', ipList)
	SKIN:Bang('!Setoption', 'netMacListString', 'string', macList)
end

function setHostString()
	local hostList = network[1][3]
	for i, v in ipairs(network) do
		if i > 1 and v[3] ~= nil then
			hostList = hostList .. "#CRLF#" .. v[3]
		end
	end
	SKIN:Bang('!Setoption', 'hostListString', 'string', hostList)
end

function ParseBTdevices()
	local info = SKIN:MakePathAbsolute(SKIN:GetVariable('@') .. 'BTdevices.txt')
-- print('fileName = ' .. info)
	BTdevices = {}
	local file = assert(io.open(info, 'r'))
	if file == nil then return false end
	for line in file:lines() do
		if line:len() > 2 then table.insert(BTdevices, {}) end
		local j = 0
		while line:find(',', j + 1) ~= nil do
			local e = line:find(',', j + 1)
			local temp = ''
			temp = line:sub(j + 1, e - 1)
-- print("temp = " .. temp)
			table.insert(BTdevices[#BTdevices], temp)
			j = e
		end
	end --end for loop through output file
	SKIN:Bang('!updateMeasure', 'connectivityInfo')
	if file ~= nil then 
		file:close()
		-- print('Found ' .. #BTdevices .. ' bluetooth devices')
		-- displayBTdevices()
		setBTnameString()
		setBTaddressString()
		setBTtypeString()
		setBTpairedString()
		setBTconnectedString()
		setBTauthenticString()
		return true 
	end
end

function displayBTdevices()
print('Found ' .. #BTdevices .. ' bluetooth devices')
	for i, v in ipairs(BTdevices) do
		local name
		if string.len(v[1]) > 1 then name = v[1]
		else name = v[2] end
		print(name .. ' address = ' .. v[3])
		print(name .. ' type = ' .. v[5] .. ' ' .. v[4])
		print(name .. ' paired = ' .. v[6])
		print(name .. ' connected = ' .. v[7])
		print(name .. ' authenticated = ' .. v[13])
	end
end

function setBTnameString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		local name
		if string.len(v[1]) > 1 then name = v[1]
		else name = v[2] end
		result = result .. name
		if i < #BTdevices then result = result  .. "#CRLF#" end
	end
	SKIN:Bang('!Setoption', 'btNameListString', 'string', result)
end

function setBTaddressString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		result = result .. v[3]
		if i < #BTdevices then
			result = result .. "#CRLF#"
		end
	end
	SKIN:Bang('!Setoption', 'btAddressListString', 'string', result)
end

function setBTtypeString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		result = result .. v[5] .. ' ' .. v[4]
		if i < #BTdevices then
			result = result .. "#CRLF#"
		end
	end
	SKIN:Bang('!Setoption', 'btTypeListString', 'string', result)
end

function setBTpairedString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		result = result .. v[6]
		if i < #BTdevices then
			result = result .. "#CRLF#"
		end
	end
	SKIN:Bang('!Setoption', 'btPairedListString', 'string', result)
end

function setBTconnectedString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		result = result .. v[7]
		if i < #BTdevices then
			result = result .. "#CRLF#"
		end
	end
	SKIN:Bang('!Setoption', 'btConnectedListString', 'string', result)
end

function setBTauthenticString()
	local result = ''
	for i, v in ipairs(BTdevices) do
		result = result .. v[13]
		if i < #BTdevices then
			result = result .. "#CRLF#"
		end
	end
	SKIN:Bang('!Setoption', 'btAuthenticListString', 'string', result)
end
