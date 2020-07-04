function Initialize()
	date = SKIN:GetMeasure('mDate'):GetStringValue()
	year = tonumber(date:sub(1,4))
	currDate = tonumber(date:sub(9))
	currMonth = tonumber(date:sub(6,7))
	currDay = SKIN:GetMeasure('mDay'):GetStringValue()
	-- print("MM/DD/YYYY = " .. currMonth .. '/' .. currDate .. '/' .. year)
	month = {}
	instantiateMonth()
end

function instantiateMonth()
	--the max number of days in current month
	maxDays = 0
	--the max number of days in previous month
	prevMaxDays = 0
	--translate weekday name into number of day in current week
	weekDay = 0
	if currDay:match('Sun') ~= nil then
		weekDay = 1
	elseif currDay:match('Mon') ~= nil then
		weekDay = 2
	elseif currDay:match('Tue') ~= nil then
		weekDay = 3
	elseif currDay:match('Wed') ~= nil then
		weekDay = 4
	elseif currDay:match('Thu') ~= nil then
		weekDay = 5
	elseif currDay:match('Fri') ~= nil then
		weekDay = 6
	elseif currDay:match('Sat') ~= nil then
		weekDay = 7
	end
	--the day of the week that the 1st falls on
	local the1st = ((7 - (currDate - weekDay)) % 7)
	-- print('the 1st falls on ' .. the1st)
	
	--is this a leap year (boolean value)
	local leapyear
	if year % 4 == 0 then
		leapyear = true
	else
		leapyear = false
	end

	--set max days for current and previous months
	if currMonth == 2 then
		if leapyear == true then
			maxDays = 29
		else maxDays = 28	end
		prevMaxDays = 31
	elseif currMonth == 3 then
		maxDays = 31
		if leapyear == true then
			prevMaxDays = 29
		else prevMaxDays = 28 end
	elseif currMonth == 5 or currMonth == 7 or currMonth == 10 or currMonth == 12 then
		maxDays = 31
		prevMaxDays = 30
	elseif currMonth == 1 or currMonth == 8 then
		maxDays = 31
		prevMaxDays = 31
	else
		maxDays = 30
		prevMaxDays = 31
	end
-- print('prevMaxDays = ' .. prevMaxDays)
	
	--instantiate week 1
	table.insert(month, {})
	for i = 1, 7 do 
		if i <= the1st then
			month[1][i] = prevMaxDays - the1st + i
		elseif the1st == 0 then
			month[1][i] = prevMaxDays - (7 - i)
		else 
			month[1][i] = i - the1st
		end
	end
	--instantiate week 2 through 6
	local d = month[1][7]
	if d >= 7 then d = 0 end
	for i = 2, 6 do
	table.insert(month, {})
		for j = 1, 7 do
			if d < maxDays then
				d = d + 1
			else
				d = 1
			end
			month[i][j] = d
		end
	end
	--[[
	--display results
	printMonth()
	]]--
	displayMonth()
end

function printMonth()
	for i, v in ipairs(month) do
		for j = 1, 7 do
			print(v[j])
		end
	end
end

function displayMonth()
	--set the color of each day's font
	local inMonth = false
	for i, v in ipairs(month) do
		for j = 1, 7 do
			if inMonth == true then
				if v[j] == currDate then
					SKIN:Bang('!SetOption', i .. '-' .. j, 'fontColor', '#Palette1#')
				else
					SKIN:Bang('!SetOption', i .. '-' .. j, 'fontColor', '#Palette5#')
				end
			else
				SKIN:Bang('!SetOption', i .. '-' .. j, 'fontColor', '#Palette7#')
			end
			if i == 1 and v[j] == prevMaxDays then inMonth = true end
			if v[j] == maxDays and i > 1 then inMonth = false end
			SKIN:Bang('!SetOption', i .. '-' .. j, 'text', v[j])
		end
	end

	--highlight the current day name
	for i = 1, 7 do
		if i == weekDay then
			SKIN:Bang('!SetOption', '0-' .. i, 'fontColor', '#Palette1#')
		else
			SKIN:Bang('!SetOption', '0-' .. i, 'fontColor', '#Palette6#')
		end
	end
end

function Update()
	local tempDate = SKIN:GetMeasure('mDate'):GetStringValue()
	if tempDate ~= date then 
		deallocate()
		date = tempDate
		year = tonumber(date:sub(1,4))
		currDate = tonumber(date:sub(9))
		currMonth = tonumber(date:sub(6,7))
		currDay = SKIN:GetMeasure('mDay'):GetStringValue()
		instantiateMonth()
	end
end

function deallocate()
	local weeks = 0
	local days = 0
	for i, v in ipairs(month) do
		for j = 1, 7 do
			table.remove(v)
			days = days + 1
		end
		table.remove(v, i)
		weeks = weeks + 1
	end
	--print('deallocated ' .. weeks .. ' weeks and ' .. days .. ' days')
end
