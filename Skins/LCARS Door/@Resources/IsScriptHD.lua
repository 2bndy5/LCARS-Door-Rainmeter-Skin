function Initialize()
	str = ""
	H = 0
	W = 0
end

--parses output from identify.exe to set original source image's W&H
function Update()
	str = SKIN:GetMeasure('mIsHD'):GetStringValue()
	if str:len() > 1 then
		local W = tonumber(str:match('(%d+)x'))
		local H = tonumber(str:match('x(%d+)'))
		--print('W, H = ' .. W .. ', ' .. H)
		if W >= 1280 and H >= 720 then return 'true'
		else return 'false' end
	end
	return 'false'
end
