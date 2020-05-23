function HSVtoRGB(Hue, Sat, Val)
	local h = Hue * 6
	local chroma = Val * Sat
	local mid = chroma * (1 - math.abs(h % 2 - 1))
	local Match = Val - chroma
--[[for Debug
	SKIN:Bang('!Log', "h = " .. h, 'Debug')
	SKIN:Bang('!Log', "Chroma = " .. chroma, 'Debug')
	SKIN:Bang('!Log', "mid = " .. mid, 'Debug')
	SKIN:Bang('!Log', "match = " .. Match, 'Debug')
]]--
	local newRGB = {}
	if 0 <= h and h < 1 then
		newRGB[1] = 255 * (chroma + Match)
		newRGB[2] = 255 * (mid + Match)
		newRGB[3] = 255 * (0 + Match)
	elseif 1 <= h and h < 2 then
		newRGB[1] = 255 * (mid + Match)
		newRGB[2] = 255 * (chroma + Match)
		newRGB[3] = 255 * (0 + Match)
	elseif 2 <= h and h < 3 then
		newRGB[1] = 255 * (0 + Match)
		newRGB[2] = 255 * (chroma + Match)
		newRGB[3] = 255 * (mid + Match)
	elseif 3 <= h and h < 4 then
		newRGB[1] = 255 * (0 + Match)
		newRGB[2] = 255 * (mid + Match)
		newRGB[3] = 255 * (chroma + Match)
	elseif 4 <= h and h < 5 then
		newRGB[1] = 255 * (mid + Match)
		newRGB[2] = 255 * (0 + Match)
		newRGB[3] = 255 * (chroma + Match)
	elseif 5 <= h and h <= 6 then
		newRGB[1] = 255 * (chroma + Match)
		newRGB[2] = 255 * (0 + Match)
		newRGB[3] = 255 * (mid + Match)
	end--set newRGB table
	for i = 1, 3, 1 do
		newRGB[i] = math.floor(newRGB[i] + 0.5)
	end
	return table.concat(newRGB, ',')
end
function setHueColor(h)
	SKIN:Bang('!SetVariable', 'HueColor', HSVtoRGB(h, 1, 1))
end

function getHue(rgb)
	local hue
	if (2*rgb[1]-rgb[2]-rgb[3]) == 0 then
		hue = 0
		greyscale = true
		if rgb[1] / 255 <= 0.25 then
			maxVal = 0.25
			invertColors = true
--			print('inverting Color scheme')
		else
			invertColors = false
			maxVal = rgb[1] / 255
		end
	else
		hue = math.atan2((math.sqrt(3)*(rgb[2]-rgb[3])), (2*rgb[1]-rgb[2]-rgb[3]))
	end
	if hue < 0.0 then
		hue = hue + 6
	end
--	SKIN:Bang('!Log', hue, 'Debug')
	return hue / 6
end

function setTNGpalete()
	SKIN:Bang('!SetVariable', 'palette1', '255,255,153')
	SKIN:Bang('!SetVariable', 'palette2', '188,88,140')
	SKIN:Bang('!SetVariable', 'palette3', '255,153,51')
	SKIN:Bang('!SetVariable', 'palette4', '255,204,102')
	SKIN:Bang('!SetVariable', 'palette5', '119,68,102')
	SKIN:Bang('!SetVariable', 'palette6', '68,85,187')
	SKIN:Bang('!SetVariable', 'palette7', '102,136,204')
end

function setNemesisPalette()
	SKIN:Bang('!SetVariable', 'palette1', '153,204,255')
	SKIN:Bang('!SetVariable', 'palette2', '119,159,225')
	SKIN:Bang('!SetVariable', 'palette3', '28,130,185')
	SKIN:Bang('!SetVariable', 'palette4', '123,185,170')
	SKIN:Bang('!SetVariable', 'palette5', '102,153,141')
	SKIN:Bang('!SetVariable', 'palette6', '51,102,204')
	SKIN:Bang('!SetVariable', 'palette7', '3,100,146')
end

function setUserPalette()
	local palette1 = SKIN:GetVariable('customColor1', '255,255,255')
	local palette2 = SKIN:GetVariable('customColor2', '200,200,200')
	local palette3 = SKIN:GetVariable('customColor3', '185,185,185')
	local palette4 = SKIN:GetVariable('customColor4', '150,150,150')
	local palette5 = SKIN:GetVariable('customColor5', '100,100,100')
	local palette6 = SKIN:GetVariable('customColor6', '85,85,85')
	local palette7 = SKIN:GetVariable('customColor7', '50,50,50')
	SKIN:Bang('!SetVariable', 'palette1', palette1)
	SKIN:Bang('!SetVariable', 'palette2', palette2)
	SKIN:Bang('!SetVariable', 'palette3', palette3)
	SKIN:Bang('!SetVariable', 'palette4', palette4)
	SKIN:Bang('!SetVariable', 'palette5', palette5)
	SKIN:Bang('!SetVariable', 'palette6', palette6)
	SKIN:Bang('!SetVariable', 'palette7', palette7)
end

function Update()
	local winColors = tonumber(SKIN:GetVariable('WinColors'))
	local TNGcolors = tonumber(SKIN:GetVariable('TNGcolors'))
	local NemesisColors = tonumber(SKIN:GetVariable('NemesisColors'))
	local CustomColors = tonumber(SKIN:GetVariable('CustomColors'))
	local UseSchemes = tonumber(SKIN:GetVariable('UseSchemes'))
	local Hue = 0
	greyscale = false
	invertColors = false
	maxVal = 1
	if TNGcolors == 0 then
		setTNGpalete()
	elseif NemesisColors == 0 then
		setNemesisPalette()
	elseif CustomColors == 0 then
		setUserPalette()
	else
		if winColors == 0 then
			local color = SKIN:GetMeasure('GetBaseColor'):GetStringValue()
			local hex = ('%08X'):format(tonumber(color))
			local rgb = { tonumber(string.sub(hex, 3, 4), 16), tonumber(string.sub(hex, 5, 6), 16), tonumber(string.sub(hex, 7, 8), 16) }
			Hue = getHue(rgb)
		else	
			Hue = tonumber(SKIN:GetVariable('hue'))
			if Hue > 1 then 
				Hue = 1 
			elseif Hue < 0 then
				Hue = 0
			end
		end
		if greyscale == false then 
			SKIN:Bang('!SetVariable', 'BgColor', '0,0,0')
			SKIN:Bang('!SetVariable', 'palette1', HSVtoRGB(Hue, 0.3, 1))
			SKIN:Bang('!SetVariable', 'palette2', HSVtoRGB(Hue, 0.5, 1))
			SKIN:Bang('!SetVariable', 'palette3', HSVtoRGB(Hue, 0.65, 1))
			SKIN:Bang('!SetVariable', 'palette4', HSVtoRGB(Hue, 0.8, 0.8))
			SKIN:Bang('!SetVariable', 'palette5', HSVtoRGB(Hue, 1, 0.65))
			SKIN:Bang('!SetVariable', 'palette6', HSVtoRGB(Hue, 1, 0.5))
			SKIN:Bang('!SetVariable', 'palette7', HSVtoRGB(Hue, 1, 0.3))
		else
			if invertColors == false then
				SKIN:Bang('!SetVariable', 'BgColor', '0,0,0')
				SKIN:Bang('!SetVariable', 'palette1', HSVtoRGB(1, 0, ((1 - maxVal) * 0.75 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette2', HSVtoRGB(1, 0, ((1 - maxVal) * 0.666 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette3', HSVtoRGB(1, 0, ((1 - maxVal) * 0.333 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette4', HSVtoRGB(1, 0, maxVal))
				SKIN:Bang('!SetVariable', 'palette5', HSVtoRGB(1, 0, (maxVal * 0.666)))
				SKIN:Bang('!SetVariable', 'palette6', HSVtoRGB(1, 0, (maxVal * 0.333)))
				SKIN:Bang('!SetVariable', 'palette7', HSVtoRGB(1, 0, (maxVal * 0.25)))
			else 
				SKIN:Bang('!SetVariable', 'BgColor', '255,255,255')
				SKIN:Bang('!SetVariable', 'palette7', HSVtoRGB(1, 0, ((1 - maxVal) * 0.7 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette6', HSVtoRGB(1, 0, ((1 - maxVal) * 0.666 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette5', HSVtoRGB(1, 0, ((1 - maxVal) * 0.333 + maxVal)))
				SKIN:Bang('!SetVariable', 'palette4', HSVtoRGB(1, 0, maxVal))
				SKIN:Bang('!SetVariable', 'palette3', HSVtoRGB(1, 0, (maxVal * 0.666)))
				SKIN:Bang('!SetVariable', 'palette2', HSVtoRGB(1, 0, (maxVal * 0.333)))
				SKIN:Bang('!SetVariable', 'palette1', HSVtoRGB(1, 0, (maxVal * 0.2)))
			end
		end
	end
	setHueColor(Hue)
	return Hue
end