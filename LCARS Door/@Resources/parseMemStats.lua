function Initialize()
    bank = {}
    size = {}
    form = {}
    type = {}
    speed = {}
    typeSub = {
        [0]="Unknown",
        [1]="Other", 
        [2]="DRAM", 
        [3]="Synch DRAM", 
        [4]="Cache DRAM", 
        [5]="EDO", 
        [6]="EDRAM", 
        [7]="VRAM", 
        [8]="SRAM", 
        [9]="RAM", 
        [10]="ROM", 
        [11]="Flash", 
        [12]="EEPROM", 
        [13]="FEPROM", 
        [14]="EPROM", 
        [15]="CDRAM", 
        [16]="3DRAM", 
        [17]="SDRAM", 
        [18]="SGRAM", 
        [19]="RDRAM", 
        [20]="DDR", 
        [21]="DDR2", 
        [22]="DDR2 FB-DIMM", 
        [24]="DDR3", 
        [25]="FBD2",
        [26]="DDR4" }
    formSub = {
        [0]="Unknown",
        [1]="Other",
        [2]="SIP",
        [3]="DIP",
        [4]="ZIP",
        [5]="SOJ",
        [6]="Proprietary",
        [7]="SIMM",
        [8]="DIMM",
        [9]="TSOP",
        [10]="PGA",
        [11]="RIMM",
        [12]="SODIMM",
        [13]="SRIMM",
        [14]="SMD",
        [15]="SSMP",
        [16]="QFP",
        [17]="TQFP",
        [18]="SOIC",
        [19]="LCC",
        [20]="PLCC",
        [21]="BGA",
        [22]="FPBGA",
        [23]="LGA" }
end

function Update()
    rawData = SKIN:GetMeasure('GetMemStats'):GetStringValue()
    -- print(rawData)
    parseData(rawData)
    SKIN:Bang('!SetVariable', 'NumbMemChip', #bank)
    SKIN:Bang('!setOption', 'MemBanks', 'string', table.concat(bank, '#CRLF#'))
    SKIN:Bang('!setOption', 'MemSizes', 'string', table.concat(size, '#CRLF#'))
    SKIN:Bang('!setOption', 'MemForms', 'string', table.concat(form, '#CRLF#'))
    SKIN:Bang('!setOption', 'MemTypes', 'string', table.concat(type, '#CRLF#'))
    SKIN:Bang('!setOption', 'MemSpeeds', 'string', table.concat(speed, '#CRLF#'))
end

function scaleSize(n)
    if n > 1073741824 then
        return (n / 1073741824) .. ' Gb'
    elseif n > 1048576 then
        return (n / 1048576) .. ' Mb'
    end
    return (n / 1024) .. ' kb'
end

function parseData(str)
    lineIndex = string.find(str, '\n')
    line = string.match(str, '\n(.*)\n', lineIndex)
    -- print(line)
    while line ~= nil and line:len() > 0 do
        table.insert(bank, string.match(line, '%a-(%d)%s'))
        -- print('bank ' .. bank[#bank])
        table.insert(size, scaleSize(tonumber(string.match(line, '%a-%d%s+(%d+)%s'))))
        -- print('size ' .. size[#size])
        table.insert(form, formSub[tonumber(string.match(line, '%a-%d%s+%d+%s+(%d+)%s'))])
        -- print('form ' .. form[#form])
        table.insert(type, typeSub[tonumber(string.match(line, '%a-%d%s+%d+%s+%d+%s+(%d+)%s'))])
        -- print('type ' .. type[#type])
        table.insert(speed, string.match(line, '%a-%d%s+%d+%s+%d+%s+%d+%s+(%d+)%s'))
        -- print('speed ' .. speed[#speed])
        lineIndex = string.find(str, '\n', lineIndex + 1)
        line = string.match(str, '\n(.*)\n', lineIndex)
        -- print(line .. 'len = ' .. line:len())
    end
end

--[[ from my laptop
BankLabel  Capacity    FormFactor  SMBIOSMemoryType  Speed  
BANK0      4294967296  12          24                1600   
BANK1      8589934592  12          24                1600   
--]]
