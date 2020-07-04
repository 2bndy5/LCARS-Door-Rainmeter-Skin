function Initialize()
	math.randomseed( os.time() )
end

function Update()
	bytes = SKIN:GetMeasure('CalcHexBits'):GetValue() / 4 - 1
	randomHex = ('%04X'):format(tonumber(math.random(0, 65535)))
	for i = 1, bytes, 1 do
		temp = ('%04X'):format(tonumber(math.random(0, 65535)))
		randomHex = randomHex .. ' ' .. temp
	end
	return randomHex
end