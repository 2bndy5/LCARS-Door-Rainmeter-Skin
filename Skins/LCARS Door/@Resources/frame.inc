
[dynamicH1]
measure=calc
dynamicVariables=1
formula=round((#MaxH# - 546) * 21 / 76)

[dynamicH2]
measure=calc
dynamicVariables=1
formula=round((#MaxH# - 546) * 55 / 76)

[Border_cornerTL]
meter=shape
x=0
y=0
dynamicVariables=1
meterStyle=CornerTL

[Border_Horizontal_Top]
meter=shape
x=R
y=r
dynamicVariables=1
shape=Rectangle 0,0,(#MaxW#-273),27 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle (#MaxW#-273),11,13,16
shape3=Combine shape | union shape2
shape4=Line (#MaxW#-273),11,(#MaxW#-271),11 | strokeWidth 22 | StrokeColor [mRandomPalette2] | StrokeEndCap Round
shape5=Rectangle 5,0,(#MaxW#-283),22 | StrokeWidth 0 | Fill Color [mRandomPalette4]

[Border_VerticleL1]
meter=shape
dynamicVariables=1
x=[Border_cornerTL:x]
y=[Border_cornerTL:H]
shape=Rectangle 0,0,260,42 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,32 | StrokeWidth 0 | Fill Color [mRandomPalette3]

[Border_VerticleL2]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette5]

[Border_VerticleL3]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,42 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,32 | StrokeWidth 0 | Fill Color [mRandomPalette2]

[Border_VerticleL4]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette1]

[Border_VerticleL5]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,([dynamicH1]<32?0:[dynamicH1]) | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,([dynamicH1]<32?0:5),113,([dynamicH1]<32?0:[dynamicH1]-10) | StrokeWidth 0 | Fill Color [mRandomPalette4]

[Border_VerticleL6]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,([dynamicH1]<32?[dynamicH1]+[dynamicH2]:[dynamicH2]) | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,([dynamicH1]<32?[dynamicH1]+[dynamicH2]-10:[dynamicH2]-10) | StrokeWidth 0 | Fill Color [mRandomPalette5]

[Border_VerticleL7]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette1]

[Border_Horizontal_Bottom]
meter=shape
x=r
y=R
dynamicVariables=1
shape=Rectangle 13,0,(#MaxW#-273),27 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 0,0,13,16
shape3=Combine shape | union shape2
shape4=Line 11,16,13,16 | strokeWidth 22 | StrokeColor [mRandomPalette4] | StrokeStartCap Round
shape5=Rectangle 18,5,(#MaxW#-283),22 | StrokeWidth 0 | Fill Color [mRandomPalette3]

[Border_cornerBR]
meter=shape
x=R
y=([Border_Horizontal_Bottom:Y]+[Border_Horizontal_Bottom:H]-105)
dynamicVariables=1
meterStyle=CornerBR

[Border_VerticleR1]
meter=shape
dynamicVariables=1
x=([Border_Horizontal_Top:X]+[Border_Horizontal_Top:W]-260)
y=([Border_Horizontal_Top:H])
shape=Rectangle 0,0,260,42 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,32 | StrokeWidth 0 | Fill Color #Palette3#

[Border_VerticleR2]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette4]

[Border_VerticleR3]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette5]

[Border_VerticleR4]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,42 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,32 | StrokeWidth 0 | Fill Color [mRandomPalette2]

[Border_VerticleR5]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,110 | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,100 | StrokeWidth 0 | Fill Color [mRandomPalette3]

[Border_VerticleR6]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,([dynamicH1]<32?0:[dynamicH1]) | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,([dynamicH1]<32?0:5),113,([dynamicH1]<32?0:[dynamicH1]-10) | StrokeWidth 0 | Fill Color [mRandomPalette4]

[Border_VerticleR7]
meter=shape
dynamicVariables=1
x=r
y=R
shape=Rectangle 0,0,260,([dynamicH1]<32?[dynamicH1]+[dynamicH2]:[dynamicH2]) | StrokeWidth 0 | Fill Color #BgColor#,#BgAlpha#
shape2=Rectangle 147,5,113,([dynamicH1]<32?[dynamicH1]+[dynamicH2]-10:[dynamicH2]-10) | StrokeWidth 0 | Fill Color [mRandomPalette5]

[MainBG]
meter=image
DynamicVariables=1
x=([Border_cornerTL:W])
y=([Border_Horizontal_Top:H])
w=([Border_cornerBR:X]-[#CurrentSection#:X])
h=([Border_Horizontal_Bottom:Y]-[#CurrentSection#:Y])
solidColor=#BgColor#,#BgAlpha#

[CloseButton]
meter=string
meterStyle=LcarsFont
Text="Close"
w=111
x=([Border_VerticleR1:X]+[Border_VerticleR1:W]-3)
y=([Border_VerticleR1:Y]+([Border_VerticleR1:H]/2)+2)
solidColor=0,0,0,1
stringAlign=RightCenter
LeftMouseUpAction=[!deActivateConfig "#CurrentConfig#"]
