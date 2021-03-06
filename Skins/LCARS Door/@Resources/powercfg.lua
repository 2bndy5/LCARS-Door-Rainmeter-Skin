function buildData()
	SKIN:Bang('!SetVariable', 'MaxItemCount', buildActive() )
	buildPlans()
	end

function displayGroups()
	for i, v in ipairs(groups) do
		--SKIN:Bang('!Log', 'i = ' .. i, 'Debug')
		SKIN:Bang('!Log', v[1] .. ' = ' .. v[2], 'Debug')
		SKIN:Bang('!Log', 'subSections = ' .. v[4], 'Debug')
	end
end

function displayPlans()
	for i, v in ipairs(plans) do
		SKIN:Bang('!Log', 'Name[' .. i .. '] = ' .. v[1], 'Debug')
		SKIN:Bang('!Log', 'GUID[' .. i .. '] = ' .. v[2], 'Debug')
	end --end for each plan
end

function displaySection(g, s)
--g = specifies the desired group
--j = specifies the desired section
	SKIN:Bang('!Log', groups[g][3][s][1] .. ' = ' .. groups[g][3][s][2], 'Debug')
	if type(groups[g][3][s][3]) == 'string' then
		SKIN:Bang('!Log', 'units = ' .. groups[g][3][s][3], 'Debug')
	else
		SKIN:Bang('!Log', 'options = ' .. groups[g][3][s][3], 'Debug')
	end
	SKIN:Bang('!Log', 'AC = ' .. groups[g][3][s][4], 'Debug')
	SKIN:Bang('!Log', 'DC = ' .. groups[g][3][s][5], 'Debug')
end

function displayParameters(g, s)
--g = specifies the desired group
--j = specifies the desired section
	for p = 1, countParameters(g, s) * 2, 2 do
		SKIN:Bang('!Log', groups[g][3][s][6][p] .. ' = ' .. groups[g][3][s][6][p+1], 'Debug')
	end
end

function getGroupName(i)
--i = specifies desired subGroup
	return groups[i][1]
end

function getGroupGUID(i)
--i = specifies desired subGroup
	return groups[i][2]
end

function getSectionName(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	return groups[i][3][j][1]
end

function getSectionGUID(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	return groups[i][3][j][2]
end

function getSectionAC(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	return groups[i][3][j][4]
end

function getSectionDC(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	return groups[i][3][j][5]
end

function hasUnits(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	if type(groups[i][3][j][3]) == 'string' then
		return true
	else return false
	end
end

function matchParameterName(index, g, s)
--index = current setting to translate into a human understanding
--g = specifies desired subGroup
--s = specifies desired subSection
	for i = 2, countParameters(g, s) * 2, 2 do
		if index == tonumber(groups[g][3][s][6][i - 1]) then 
			return groups[g][3][s][6][i] --return "friendly name"
		end --end compare str it parameter value
	end --end compare all parameters
	return nil
end

function matchParameterIndex(str, g, s)
--str = current setting to translate into powercfg understanding
--g = specifies desired subGroup
--s = specifies desired subSection
	for i = 1, countParameters(g, s) * 2, 2 do
		if str:match(groups[g][3][s][6][i + 1]) ~= nil then 
			return groups[g][3][s][6][i] --return settings index
		end --end compare str it parameter value
	end --end compare all parameters
	return nil
end

function getUnits(i, j)
	if type(groups[i][3][j][3]) == 'string' then 
		return groups[i][3][j][3]
	else return nil end
end

function dec2hex(i) --deprecated, no need for converting user input into hexadecimal
--i = represents user input to be translated into hexadecimal
	return ('%X'):format(i)
end

function setValue()
	local section = SKIN:GetVariable('section')
	local g = tonumber(SKIN:GetVariable('group'):match('%d+'))
	local s = tonumber(section:match('%d+'))
	local p = tonumber(string.match(SKIN:GetVariable('newValue'), '%d+'))
	local newValue
	local schemeGUID = plans[1][2]
	local gGUID = getGroupGUID(g)
	local sGUID = getSectionGUID(g, s)
	if hasUnits(g, s) == true then
		local units = getUnits(g, s)
		if units == 'Minutes' then
			newValue = tonumber(p) * 60
		elseif units == 'GHz' then
			newValue = tonumber(p) * 1000
		elseif units == '%' then
			newValue = tonumber(p)
		end -- end scale and translate value for corresponding units in hexadecimal
	else --if no units, then get the matching index for the value
--SKIN:Bang('!Log', groups[g][3][s][6][p * 2 - 1] .. ' = ' .. groups[g][3][s][6][p * 2], 'Debug')
		newValue = groups[g][3][s][6][p * 2 - 1]
	end -- end adjust value for appropiate setting accordingly
	
	local prog
	local exec = schemeGUID .. ' ' .. gGUID .. ' ' .. sGUID .. ' ' .. newValue
	if section:find('AC') then
		prog = 'powercfg -setacvalueindex '
	else
		prog = 'powercfg -setdcvalueindex '
	end -- end create shell commands
	
--SKIN:Bang('!setVariable', 'execute', prog .. exec )
SKIN:Bang('!setoption', 'changeValue', 'parameter', '\"' .. prog .. exec .. '\"')
SKIN:Bang('!updateMeasure', 'changeValue')
SKIN:Bang('!commandMeasure', 'changeValue', 'run')
--now flush groups[] and rebuild data
cleanUp()
SKIN:Bang('!commandMeasure', 'getActivePowerScheme', 'Run')
--[[
	local success = os.execute(prog .. exec)
	if tonumber(success) ~= 0 then
		SKIN:Bang('!Log', prog .. exec, 'Debug')
		SKIN:Bang('!Log', 'no success; status = ' .. success, 'Debug')
	else
--SKIN:Bang('!Log', 'great success; status = ' .. success, 'Debug')
		--now flush groups[] and rebuild data
		cleanUp()
		SKIN:Bang('!commandMeasure', 'getActivePowerScheme', 'Run')
	end --end pass shell commands
]]--
	--updateCurrentSettingValue(g, section)
end

function updateCurrentSettingValue(g, section)
--g = specifies subGroup number
--section = specifies subSection and either AC or DC
	local s = tonumber(section:match("%d+"))
	if section:find("AC") ~= nil then
		local sCurrent = getSectionAC(g, s)
		if type(sCurrent) == 'string' then sCurrent = 0 end
		SKIN:Bang('!SetOption', 'sCurrent', 'formula', tonumber(sCurrent))
	else
		local sCurrent = getSectionDC(g, s)
		if type(sCurrent) == 'string' then sCurrent = 0 end
		SKIN:Bang('!SetOption', 'sCurrent', 'formula', tonumber(sCurrent))
	end
	SKIN:Bang('!updateMeter', 'parameterSlider')		
end

function displayOptionP()
--call this function to retrieve options the subSection contains and display them
	local g = tonumber(string.match(SKIN:GetVariable('group'), "%d+"))
	local setting = SKIN:GetVariable('section')
	local s = tonumber(setting:match("%d+"))
	local currPnumb = tonumber(countParameters(g, s))
	SKIN:Bang('!setOption', 'pCount', 'formula', currPnumb )
	if hasUnits(g, s) == true then
		for i = 1, 10, 2 do
			SKIN:Bang('!SetOption', 'p' .. i .. 'name', 'string', '')
		end --end clear section name strings
		updateCurrentSettingValue(g, setting)
		SKIN:Bang('!showMeterGroup', 'parameterSlider')
	else --if section doesn't have units
		for i = 2, 10, 2 do
			if i > currPnumb * 2 then
				SKIN:Bang('!SetOption', 'p' .. i / 2 .. 'name', 'string', '')
			else
				SKIN:Bang('!SetOption', 'p' .. i / 2 .. 'name', 'string', groups[g][3][s][6][i])
			end
		end --end set parameter friendly names
		SKIN:Bang('!showMeterGroup', 'parameterList')
--displayParameters(g, s)
	end	 --end if section has units or not
end

function displayOptionPlans()
	
	
end

function countSections(i)
--i = specifies desired subGroup
	return groups[i][4]
end

function countParameters(i, j)
--i = specifies desired subGroup
--j = specifies desired subSection
	if type(groups[i][3][j][3]) == 'number' then
		return groups[i][3][j][3]
	else return 2
	end
end

function setSectionNames(g, maxS)
	--g = specifies desired subGroup
	SKIN:Bang('!hideMeterGroup', 's'.. 10)
	for s = 1, 10 do
		if s > maxS then
			SKIN:Bang('!setOption', 's' .. s .. 'Name', 'string', '' )
			SKIN:Bang('!setOption', 's' .. s .. 'ACsetting', 'string', '' )
			SKIN:Bang('!setOption', 's' .. s .. 'DCsetting', 'string', '' )
			SKIN:Bang('!setOption', 's' .. s .. 'Units', 'string', '' )
		else
			SKIN:Bang('!setOption', 's' .. s .. 'Name', 'string', getSectionName(g, s) )
			local AC = getSectionAC(g, s)
			local DC = getSectionDC(g, s)
			if hasUnits(g, s) == true then
				SKIN:Bang('!setOption', 's' .. s .. 'Units', 'string', groups[g][3][s][3] )
				SKIN:Bang('!setOption', 's' .. s .. 'ACsetting', 'string', AC )
				SKIN:Bang('!setOption', 's' .. s .. 'DCsetting', 'string', DC )
				local units = getUnits(g, s)
				if units == 'Minutes' then
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'maxValue', 300)
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'maxValue', 300)
					--actual max value equates to 4294967295 Seconds
				elseif units == 'GHz' then
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'maxValue', 10)
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'maxValue', 10)
					--actual max value equates to 4294967295 MHz
				else
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'minValue', groups[g][3][s][6][2])
					SKIN:Bang('!SetOption', 's' .. s .. 'ACsetting', 'maxValue', groups[g][3][s][6][4])
					SKIN:Bang('!SetOption', 's' .. s .. 'DCsetting', 'maxValue', groups[g][3][s][6][4])
				end --set max and min values to section string measures
			else --section has no dynamic value (units) and accepts only static values (on, off, etc.)
				SKIN:Bang('!setOption', 's'.. s .. 'Units', 'string', '' )
				SKIN:Bang('!setOption', 's'.. s .. 'ACsetting', 'string', matchParameterName(AC, g, s))
				SKIN:Bang('!setOption', 's'.. s .. 'DCsetting', 'string', matchParameterName(DC, g, s))
			end
		end
	end
	SKIN:Bang('!showMeterGroup', 's'.. maxS )
end

function setGroupNames()
	for i, v in ipairs(groups) do
		SKIN:Bang('!setOption', 'g'.. i .. 'Name', 'string', v[1] )
	end
	SKIN:Bang('!hideMeterGroup', 'g'.. #groups + 1 )
end

function cleanUp() -- function to avoid memory leaks when power.ini skin is closed
	local totalS = 0
	local totalP = 0
	local g = 0
	while #groups > 0 do
		g = g + 1
		local sMax = groups[#groups][4]
		for s = 1, sMax do
			local pMax = 0
			if type(groups[#groups][3][s][3]) == 'number' then
				pMax = groups[#groups][3][s][3] * 2
			else pMax = 4
			end
			for p = 1, pMax do
				totalP = totalP + 1
				table.remove(groups[#groups][3][s][6]) --remove all parameters
			end --end clean subSection parameters
			for i = 1, 6 do
				table.remove(groups[#groups][3][s]) --remove all subSection info
			end --end clean subSection
			totalS = totalS + 1
		end --end clean all subSections in 1 subGroup
		for i = 1, 4 do
			table.remove(groups[#groups]) --remove all subGroup info
		end --end clean subGroup
		table.remove(groups) --remove 1 subGroup
	end --end clean all subGroups
	local schemes = 0
	while #plans > 0 do 
			schemes = schemes + 1
			table.remove(plans[#plans])
			table.remove(plans[#plans])
			table.remove(plans)
	end --end clean all power schemes
	--[[for debugging only
	SKIN:Bang('!Log', 'cleaned ' .. (totalP / 2) .. ' parameters', 'Debug')
	SKIN:Bang('!Log', 'cleaned ' .. totalS .. ' sections', 'Debug')
	SKIN:Bang('!Log', 'cleaned ' .. g .. ' groups', 'Debug')
	SKIN:Bang('!Log', 'cleaned ' .. schemes .. ' plans', 'Debug')
	]]--
end

function dumpSection(s)
	--s = the current subSection count in current subGroup
	if #groups[#groups] < 3 then
		table.insert(groups[#groups], {})
	end--ensure table for sections exists
	for i, v in ipairs(section) do
		table.insert(groups[#groups][3], {}) --insert table for subSection
		table.insert(groups[#groups][3][s], v)
	end-- end add subSection to subgroup
	table.insert(groups[#groups][3][s], {}) --insert table for parameters
	for i, v in ipairs(parameters) do
		table.insert(groups[#groups][3][s][6], v)
	end

	--now wipe data for next section
	while #section > 0 do
		for i = 1, 5 do
			table.remove(section)
		end
		table.remove(section)
	end--end wipe section data
	while #parameters > 0 do
		table.remove(parameters)
	end--end wipe parameter data
end

function buildPlans()
	local file = SKIN:GetMeasure('getAllPowerSchemes'):GetStringValue()
	plans = { {} }
	--[[ plans[] is a 2D table of available power schemes to choose from
		{ for each power scheme
			{ 1=name of power scheme, 2=GUID of power scheme
			} -- end table template for 1 power scheme
		} -- end 2D table of power schemes
		the Active power scheme is always set to 1st index. For example: the active power scheme Name = plans[1][1]; the active power scheme GUID = plans[1][2]
	]]--
	for line in file:gmatch("Power Scheme GUID[^\n]*") do 
		if line:find('%s+%*') ~= nil then
			table.insert(plans[1], line:sub(line:find("%(") + 1, line:find("%)") - 1))
			table.insert(plans[1], string.upper(line:match('%x+%-%x+%-%x+%-%x+%-%x+')))
		else
			table.insert(plans, {})
			table.insert(plans[#plans], line:sub(line:find("%(") + 1, line:find("%)") - 1))
			table.insert(plans[#plans], string.upper(line:match('%x+%-%x+%-%x+%-%x+%-%x+')))
		end -- end capture power scheme Names and GUIDs
	end -- end for each line in power scheme exported file
	SKIN:Bang('!setOption', 'activePowerScheme', 'string', plans[1][1] )
	for i = 2, 5 do
		if i > #plans then
			SKIN:Bang('!setOption', 'inactiveSchemeName' .. i, 'string', '' )
		else
			SKIN:Bang('!setOption', 'inactiveSchemeName' .. i, 'string', plans[i][1] )
		end
	end
end

function buildActive()
	groups = {} 
	section = {}
	parameters = {}
	--[[ 
	groups[] contains EVERYTHING when finished.
	section[] and parameters[] are temporary and are flushed when finished
	the structure for groups[] is as follows:
		{	for each subgroup
			{ 1=name, 2=GUID, 
				{ for each subSection
					{ 1=name, 2=GUID, 3=units (datatype string) or # of parameters (datatype number), 4=AC setting, 5=DC setting, 
						{ for each parameter
							1=parameter descriptor, 2=parameter value 
						} for every parameter, this table has 2 elements, 1 for its description and 1 for its static value, so parameter count is this table's elements / 2
					} end table template for 1 subSection
				} end 2D table for all subSections in subGroup
			, 4=subSection count } end table template for 1 subGroup
		} end 2D table for all subGroups
	I know 1st hand how confusing this can be; Please use the functions provided to query any info
	]]--
	--[[ ignoreGroup[] and ignoreSection[] will skip the named (datatype = string) subGroups and subSections and not be indexed in groups[]. The next 2 lines are here for debugging purposes only. The groups/sections I have chosen to ignore may be system dependent or just not important.
	local ignoreSection = {"Allow hybrid sleep", "Allow wake timers", "Start menu power button", "Enable adaptive brightness"}
	local ignoreGroup = {"Internet Explorer", "USB settings", "Multimedia settings", "Desktop background settings"}
	]]--
	local ignoreGroup = {}
	local ignoreSection = {}
	local subSection = 0 			--base 1 counter
	local parameterOpt = 0 		--base 1 counter
	local totalSection = 0 		--base 1 counter
	local totalParameter = 0 	--base 1 counter
	local maxSubSection = 0 	--base 1 counter
	local maxParameter = 0		--base 1 counter
	local file = SKIN:GetMeasure('getActivePowerScheme'):GetStringValue()
	local sectionUnits				--flag (datatype string) to initiate scaling
	for line in file:gmatch("[^\n]*") do 
		if line:find("Subgroup GUID: ") ~= nil then
			ignoreG = false
			for i, v in ipairs(ignoreGroup) do
				if line:find(v) ~= nil then
					ignoreG = true;
					break
				end-- end if in ignore group list
			end-- end for each ignore group list item
			if ignoreG == false then
				if #section > 0 then dumpSection(subSection) end
				if #groups > 0 then
					table.insert(groups[#groups], 4, subSection)
				end
				subSection = 0
				table.insert(groups, {}) 
				table.insert(groups[#groups], line:sub(line:find("%(") + 1, line:len() - 1))
				table.insert(groups[#groups], string.upper(line:match("%x+%-%x+%-%x+%-%x+%-%x+")))
			end-- capture subGroup info
		elseif line:find("Power Setting GUID: ") ~= nil and ignoreG == false then
			ignoreS = false
			for i, v in ipairs(ignoreSection) do
				if line:find(v) ~= nil then
					ignoreS = true
					break
				end-- end if in ignore section list
			end-- end for each ignore section list items
			if ignoreS == false then
				if #section > 0 then dumpSection(subSection) end
				sectionUnits = "none"
				subSection = subSection + 1
				totalSection = totalSection + 1
				if maxSubSection < subSection then maxSubSection = subSection end
				parameterOpt = 0
				table.insert(section, line:sub(line:find("%(") + 1, line:len() - 1))
				table.insert(section, string.upper(line:match("%x+%-%x+%-%x+%-%x+%-%x+")))
			end-- end capture subSection info
		end--end if beginning subGroup or subSection
		if ignoreG == false and ignoreS == false then
			if line:find("Minimum Possible Setting") ~= nil then
				totalParameter = totalParameter + 1
				table.insert(parameters, "Min")
				table.insert(parameters, tonumber(line:sub(line:find("0x") + 2), 16))
			elseif line:find("Maximum Possible Setting") ~= nil then
				totalParameter = totalParameter + 1
				table.insert(parameters, "Max")
				table.insert(parameters, tonumber(line:sub(line:find("0x") + 2), 16))
			elseif line:find("Possible Settings units") ~= nil then
				if line:find("MHz") ~= nil then
					sectionUnits = "GHz"
					table.insert(section, "GHz")
					--convert min & max
					sectionUnits = "GHz"
					parameters[2] = tonumber(parameters[2]) / 1000
					parameters[4] = tonumber(parameters[4]) / 1000
				elseif line:find("Seconds") then
					sectionUnits = "Minutes"
					table.insert(section, "Minutes")
					--convert min & max
					parameters[2] = tonumber(parameters[2]) / 60
					parameters[4] = tonumber(parameters[4]) / 60
				else
					table.insert(section, line:sub(line:find(": ") + 2))
				end
			elseif line:find("Possible Setting Index") ~= nil then
				table.insert(parameters, tonumber(line:sub(line:find(": ") + 2)))
				parameterOpt = parameterOpt + 1
				totalParameter = totalParameter + 1
			elseif line:find("Possible Setting Friendly Name") ~= nil then
				table.insert(parameters, line:sub(line:find(": ") + 2))
			elseif line:find("Current AC") ~= nil then
				if(parameterOpt > 0) then
					if maxParameter < parameterOpt then maxParameter = parameterOpt end
					table.insert(section, parameterOpt)
				end
				if sectionUnits == "Minutes" then
					if tonumber(line:sub(line:find("0x") + 2), 16) < 1 then
						table.insert(section, 'infinite')
					else
						table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16)/60)
					end
				elseif sectionUnits:find("GHz") ~= nil then
					if tonumber(line:sub(line:find("0x") + 2), 16) < 1 then
						table.insert(section, 'infinite')
					else
						table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16)/1000)
					end
				else
					table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16))
				end
			elseif line:find("Current DC") ~= nil then
				if sectionUnits == "Minutes" then
					if tonumber(line:sub(line:find("0x") + 2), 16) < 1 then
						table.insert(section, 'infinite')
					else
						table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16)/60)
					end
				elseif sectionUnits == "GHz" then
					if tonumber(line:sub(line:find("0x") + 2), 16) < 1 then
						table.insert(section, 'infinite')
					else
						table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16)/1000)
					end
				else
					table.insert(section, tonumber(line:sub(line:find("0x") + 2), 16))
				end
			end-- end gather section info
		end-- end if section is not ignored
	end--end for loop to read settings exported file
	table.insert(groups[#groups], 4, subSection)--save # of subSections in last group
	dumpSection(subSection)--unload last section captured into groups[]
	--[[ for debugging only
	SKIN:Bang('!Log', 'max parameter in 1 section = '.. maxParameter, 'Debug' )
	SKIN:Bang('!Log', 'max sections in 1 group = ' .. maxSubSection, 'Debug')
	SKIN:Bang('!Log', 'total parameters = ' .. totalParameter, 'Debug')
	SKIN:Bang('!Log', 'total sections = ' .. totalSection, 'Debug')
	SKIN:Bang('!Log', 'total groups = ' .. #groups, 'Debug')
	]]--
	SKIN:Bang('!setOption', 'gCount', 'formula', #groups )
	setGroupNames()
	return maxSubSection + #groups + 1
end

function Update()
	local g = tonumber(string.match(SKIN:GetVariable('group'), "%d+"))
	local s = tonumber(string.match(SKIN:GetVariable('section'), "%d+"))
	local currSnumb = tonumber(countSections(g))
	SKIN:Bang('!setOption', 'sCount', 'formula', currSnumb )
	setSectionNames(g, currSnumb)
	return g
end