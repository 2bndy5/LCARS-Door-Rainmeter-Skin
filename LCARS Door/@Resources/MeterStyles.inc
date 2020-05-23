[StarFleetEmblemNoBG]
shape=Rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]),([#CurrentSection#:H]/6) | Fill Color 00000002 | StrokeWidth 0
shape2=Ellipse ([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.475),([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.2833) | StrokeWidth 0 | Fill color #StarColor#,#Alpha# | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape3=Ellipse ([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.475),([#CurrentSection#:W]*0.38597),([#CurrentSection#:H]*0.2583) | StrokeWidth 0 | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape4=path starPoint | StrokeWidth 0 | Fill Color #StarColor#,#Alpha# | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
starPoint=([#CurrentSection#:W]*0.140351),([#CurrentSection#:H]*0.8333) | CurveTo ([#CurrentSection#:W]*0.3947),0,([#CurrentSection#:W]*0.2193),([#CurrentSection#:H]*0.425) | CurveTo ([#CurrentSection#:W]*0.6754),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.5702),([#CurrentSection#:H]*0.4167)
shape5=Curve ([#CurrentSection#:W]*0.140351),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.6754),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.4035),([#CurrentSection#:H]*0.35),([#CurrentSection#:W]*0.49123),([#CurrentSection#:H]*0.3833) | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape6=Combine shape4 | Exclude shape5
shape7=Combine shape2 | Exclude shape3 | Exclude shape6
shape8=Combine shape4 | Exclude shape5

[StarFleetEmblemOnBG]
shape=Rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]),([#CurrentSection#:H]/6) | Fill Color 00000002 | StrokeWidth 0
shape2=Ellipse ([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.475),([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.2833) | StrokeWidth 0 | Fill color #StarColor#,#Alpha# | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape3=Ellipse ([#CurrentSection#:W]*0.4123),([#CurrentSection#:H]*0.475),([#CurrentSection#:W]*0.38597),([#CurrentSection#:H]*0.2583) | StrokeWidth 0 | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape4=path starPoint | StrokeWidth 0 | Fill Color #StarColor#,#Alpha# | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
starPoint=([#CurrentSection#:W]*0.140351),([#CurrentSection#:H]*0.8333) | CurveTo ([#CurrentSection#:W]*0.3947),0,([#CurrentSection#:W]*0.2193),([#CurrentSection#:H]*0.425) | CurveTo ([#CurrentSection#:W]*0.6754),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.5702),([#CurrentSection#:H]*0.4167)
shape5=Curve ([#CurrentSection#:W]*0.140351),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.6754),([#CurrentSection#:H]*0.8333),([#CurrentSection#:W]*0.4035),([#CurrentSection#:H]*0.35),([#CurrentSection#:W]*0.49123),([#CurrentSection#:H]*0.3833) | Offset ([#CurrentSection#:W]*0.0877),([#CurrentSection#:H]*0.0833)
shape6=Combine shape4 | Exclude shape5
shape7=Rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]),([#CurrentSection#:H]/6) | StrokeWidth 0 | fill color #LogoColor#
shape8=Combine shape2 | Exclude shape3 | Exclude shape6
shape9=Combine shape4 | Exclude shape5

[LcarsFont]
DynamicVariables=1
fontFace=LCARS
solidColor=0,0,0,1
fontSize=22
fontColor=#BgColor#

[CornerTL]
shape=Ellipse  52,48.5,52,48.5 | fill Color [mRandomPalette1] | StrokeWidth 0
shape2=Rectangle 0,48.5,113,51.5
shape3=Rectangle 56.5,0,198.5,48.5
shape4=Ellipse  147.5,55,35,33
shape5=Rectangle 147.5,22,107.5,78
shape6=Rectangle 113,55,35,45 | fill Color #BgColor#,#BgAlpha# | StrokeWidth 0
shape7=Rectangle 255,0,5,105
shape8=Rectangle 0,100,255,5
shape9=combine shape6 | union shape | union shape2 | union shape3 | union shape4 | union shape5 | Union shape 7 | Union shape8
shape10=combine shape | union shape2 | union shape3 | exclude shape4 | exclude shape5 | exclude shape6

[CornerTR]
shape=Ellipse  208,48.5,52,48.5 | fill Color [mRandomPalette2] | StrokeWidth 0
shape2=Rectangle 147,48.5,113,51.5
shape3=Rectangle 5,0,198.5,48.5
shape4=Ellipse  112.5,55,35,33
shape5=Rectangle 5,22,107.5,78
shape6=Rectangle 112,55,35,45 | fill Color #BgColor#,#BgAlpha# | StrokeWidth 0
shape7=Rectangle 0,0,5,105
shape8=Rectangle 5,100,255,5
shape9=combine shape6 | union shape | union shape2 | union shape3 | union shape4 | union shape5 | Union shape 7 | Union shape8
shape10=combine shape | union shape2 | union shape3 | exclude shape4 | exclude shape5 | exclude shape6

[CornerBL]
shape=Ellipse  52,56.5,52,48.5 | fill Color [mRandomPalette3] | StrokeWidth 0
shape2=Rectangle 0,5,113,51.5
shape3=Rectangle 56.5,56.5,198.5,48.5
shape4=Ellipse  147.5,50,35,33
shape5=Rectangle 147.5,5,107.5,78
shape6=Rectangle 113,5,35,45 | fill Color #BgColor#,#BgAlpha# | StrokeWidth 0
shape7=Rectangle 255,0,5,105
shape8=Rectangle 0,0,255,5
shape9=combine shape6 | union shape | union shape2 | union shape3 | union shape4 | union shape5 | Union shape 7 | Union shape8
shape10=combine shape | union shape2 | union shape3 | exclude shape4 | exclude shape5 | exclude shape6

[CornerBR]
shape=Ellipse 208,56.5,52,48.5 | fill Color [mRandomPalette4] | StrokeWidth 0
shape2=Rectangle 147,5,113,51.5
shape3=Rectangle 5,56.5,198.5,48.5
shape4=Ellipse 112.5,50,35,33
shape5=Rectangle 5,5,107.5,78
shape6=Rectangle 112,5,35,45 | fill Color #BgColor#,#BgAlpha# | StrokeWidth 0
shape7=Rectangle 0,0,5,105
shape8=Rectangle 5,0,255,5
shape9=combine shape6 | union shape | union shape2 | union shape3 | union shape4 | union shape5 | Union shape 7 | Union shape8
shape10=combine shape | union shape2 | union shape3 | exclude shape4 | exclude shape5 | exclude shape6

[div]
shape=Arc 11,22,11,0 | StrokeWidth 0 | Fill Color #Palette5#
shape2=Line 16,11,(#CurrentConfigWidth#-253),11 | StrokeWidth 22 | StrokeColor #Palette5#
shape3=arc (#CurrentConfigWidth#-247),0,(#CurrentConfigWidth#-247),22 | StrokeWidth 0 | Fill Color #Palette5#

[FullCircle]
W=60
H=60
StartAngle=4.712
RotationAngle=6.283
lineStart=15
LineLength=30
Solid=1
dynamicVariables=1

[navigation]
dynamicVariables=1
shape=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:W],([#CurrentSection#:W]*0.1) 
shape2=Rectangle (([#CurrentSection#:W]/2)-([Loop:/100]*(([#CurrentSection#:W]+40)/2))),(([#CurrentSection#:W]/2)-([Loop:/100]*(([#CurrentSection#:W]+10)/2))),([Loop:/100]*([#CurrentSection#:W]+40)),([Loop:/100]*([#CurrentSection#:W]+10)),([Loop:/100]*([#CurrentSection#:W]/10)) |  StrokeWidth 0 | Fill Color #Palette3#
shape3=Rectangle (([#CurrentSection#:W]/2)-([Loop:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop:/100]*([#CurrentSection#:W]/2))),([Loop:/100]*([#CurrentSection#:W])),([Loop:/100]*([#CurrentSection#:W])),([Loop:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0
shape4=Rectangle (([#CurrentSection#:W]/2)-([Loop:/100]*([#CurrentSection#:W]/3))),-5,([Loop:/100]*([#CurrentSection#:W]*2/3)),([#CurrentSection#:W]+10) | StrokeWidth 0
shape5=Rectangle (([#CurrentSection#:W]/2)-([Loop:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop:/100]*([#CurrentSection#:W]/2))),([Loop:/100]*([#CurrentSection#:W])),([Loop:/100]*([#CurrentSection#:W])),([Loop:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0 | Fill Color 255,255,255,15
shape6=Combine shape2 | Exclude shape3 | Exclude shape4 | intersect shape
shape7=Rectangle (([#CurrentSection#:W]/2)-([Loop2:/100]*(([#CurrentSection#:W]+40)/2))),(([#CurrentSection#:W]/2)-([Loop2:/100]*(([#CurrentSection#:W]+10)/2))),([Loop2:/100]*([#CurrentSection#:W]+40)),([Loop2:/100]*([#CurrentSection#:W]+10)),([Loop2:/100]*([#CurrentSection#:W]/10)) |  StrokeWidth 0 | Fill Color #Palette3#
shape8=Rectangle (([#CurrentSection#:W]/2)-([Loop2:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop2:/100]*([#CurrentSection#:W]/2))),([Loop2:/100]*([#CurrentSection#:W])),([Loop2:/100]*([#CurrentSection#:W])),([Loop2:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0
shape9=Rectangle (([#CurrentSection#:W]/2)-([Loop2:/100]*([#CurrentSection#:W]/3))),-5,([Loop2:/100]*([#CurrentSection#:W]*2/3)),([#CurrentSection#:W]+10) | StrokeWidth 0
shape10=Rectangle (([#CurrentSection#:W]/2)-([Loop2:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop2:/100]*([#CurrentSection#:W]/2))),([Loop2:/100]*([#CurrentSection#:W])),([Loop2:/100]*([#CurrentSection#:W])),([Loop2:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0 | Fill Color 255,255,255,15
shape11=Combine shape7 | Exclude shape8 | Exclude shape9 | intersect shape
shape12=Rectangle (([#CurrentSection#:W]/2)-([Loop3:/100]*(([#CurrentSection#:W]+40)/2))),(([#CurrentSection#:W]/2)-([Loop3:/100]*(([#CurrentSection#:W]+10)/2))),([Loop3:/100]*([#CurrentSection#:W]+40)),([Loop3:/100]*([#CurrentSection#:W]+10)),([Loop3:/100]*([#CurrentSection#:W]/10)) |  StrokeWidth 0 | Fill Color #Palette3#
shape13=Rectangle (([#CurrentSection#:W]/2)-([Loop3:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop3:/100]*([#CurrentSection#:W]/2))),([Loop3:/100]*([#CurrentSection#:W])),([Loop3:/100]*([#CurrentSection#:W])),([Loop3:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0
shape14=Rectangle (([#CurrentSection#:W]/2)-([Loop3:/100]*([#CurrentSection#:W]/3))),-5,([Loop3:/100]*([#CurrentSection#:W]*2/3)),([#CurrentSection#:W]+10) | StrokeWidth 0
shape15=Rectangle (([#CurrentSection#:W]/2)-([Loop3:/100]*([#CurrentSection#:W]/2))),(([#CurrentSection#:W]/2)-([Loop3:/100]*([#CurrentSection#:W]/2))),([Loop3:/100]*([#CurrentSection#:W])),([Loop3:/100]*([#CurrentSection#:W])),([Loop3:/100]*([#CurrentSection#:W]/10)) | StrokeWidth 0 | Fill Color 255,255,255,15
shape16=Combine shape12 | Exclude shape13 | Exclude shape14 | intersect shape

[powerCore]
dynamicVariables=1
Caps=StrokeWidth ([CoreSegHSep]) | StrokeColor #Palette6# | Fill Color #Palette6#
TopCap1=([CoreSegHSep]/2),([CoreSegHSep]/2) | LineTo ([mCalcCoreAniW]-[CoreSegHSep:/2]),([CoreSegHSep]/2) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]*17/18),([mCoreSegH]*0.495-[CoreSegHSep:/2]) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]/18),([mCoreSegH]*0.495-[CoreSegHSep:/2]) | SetRoundJoin 1 | ClosePath 1
TopCap2=([mCalcCoreAniW]/14),([mCoreSegH]*0.495+[CoreSegHSep]) | LineTo ([mCalcCoreAniW]*13/14),([mCoreSegH]*0.495+[CoreSegHSep]) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]*8/9),([mCoreSegH]*0.99-[CoreSegHSep:/2]) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]/9),([mCoreSegH]*0.99-[CoreSegHSep:/2]) | SetRoundJoin 1 | ClosePath 1
TopCap3=([mCalcCoreAniW]/8),([mCoreSegH]*0.99+[CoreSegHSep]) | LineTo ([mCalcCoreAniW]*7/8),([mCoreSegH]*0.99+[CoreSegHSep]) | SetRoundJoin 1 | LineTo([mCalcCoreAniW]*5/6),([mCoreSegH]*1.5-([CoreSegHSep]/2)) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]/6),([mCoreSegH]*1.5-([CoreSegHSep]/2)) | SetRoundJoin 1 | ClosePath 1
BottomCap1=([mCalcCoreAniW]/6),([animationH]-([mCoreSegH]*1.5-[CoreSegHSep:/2])) | LineTo ([mCalcCoreAniW]*5/6),([animationH]-([mCoreSegH]*1.5-[CoreSegHSep:/2])) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]*7/8),([animationH]-([mCoreSegH]*0.99+[CoreSegHSep])) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]/8),([animationH]-([mCoreSegH]*0.99+[CoreSegHSep])) | SetRoundJoin 1 | ClosePath 1
BottomCap2=([mCalcCoreAniW]/9),([animationH]-([mCoreSegH]*0.99-[CoreSegHSep:/2])) | LineTo ([mCalcCoreAniW]*8/9),([animationH]-([mCoreSegH]*0.99-[CoreSegHSep:/2])) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]*15/16),([animationH]-([mCoreSegH]*0.495+[CoreSegHSep:/2])) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]/16),([animationH]-([mCoreSegH]*0.495+[CoreSegHSep:/2])) | SetRoundJoin 1 | ClosePath 1
BottomCap3=([mCalcCoreAniW]/20),([animationH]-([mCoreSegH]*0.495-[CoreSegHSep])) | LineTo ([mCalcCoreAniW]*19/20),([animationH]-([mCoreSegH]*0.495-[CoreSegHSep])) | SetRoundJoin 1 | LineTo ([mCalcCoreAniW]-[CoreSegHSep]/2),([animationH]-[CoreSegHSep:/2]) | SetRoundJoin 1 | LineTo ([CoreSegHSep:/2]),([animationH]-[CoreSegHSep:/2]) | SetRoundJoin 1 | ClosePath 1
LightGrad=90 | #Palette4# ; ([LoopU:/100]-0.1) | #Palette1# ; ([LoopU:/100]) | #Palette4# ; (([LoopU:/100]+0.1)<0.5?([LoopU:/100]+0.1):0.5) | #Palette4# ; (([LoopD:/100]-0.1)<0.4?0.4:([LoopD:/100]-0.1)) | #Palette1# ; ([LoopD:/100])  | #Palette4# ; ([LoopD:/100]+0.1)
GlowGrad=0,0 | #Palette4# ; 1.0 | #Palette1# ; (abs([Loop:/100]))
shape=path TopCap1 | extend Caps
shape2=path TopCap2 | extend Caps
shape3=path TopCap3 | extend Caps
shape4=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*1.5+[CoreSegHSep]),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0 | Fill LinearGradient LightGrad
shape5=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*2.5+([CoreSegHSep]*2)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape6=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*3.5+([CoreSegHSep]*3)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape7=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*4.5+([CoreSegHSep]*4)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape8=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*5.5+([CoreSegHSep]*5)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape9=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*8.5+([CoreSegHSep]*7)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape10=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*9.5+([CoreSegHSep]*8)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape11=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*10.5+([CoreSegHSep]*9)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape12=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*11.5+([CoreSegHSep]*10)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape13=Rectangle ([mCalcCoreAniW]/10),([mCoreSegH]*12.5+([CoreSegHSep]*11)),([mCalcCoreAniW]*4/5),([mCoreSegH]),([mCoreSegH]/2) |  StrokeWidth 0
shape14=path BottomCap1 | extend Caps
shape15=path BottomCap2 | extend Caps
shape16=path BottomCap3 | extend Caps
shape17=Ellipse ([mCalcCoreAniW]/2),([animationH]/2),(([mCoreSegH]*3/4)-[CoreSegHSep:/2]) | StrokeWidth 0 | Fill RadialGradient GlowGrad
shape18=Rectangle ([CoreSegHSep:/2]),([mCoreSegH]*6.5+([CoreSegHSep]*6.5)),([mCalcCoreAniW]-[CoreSegHSep]),([mCoreSegH]*2-[CoreSegHSep]),([mCoreSegH:/2]) | extend Caps
shape19=Rectangle 0,(([animationH]/2)-[mCoreSegH:/2]),([mCalcCoreAniW]),([mCoreSegH]) | StrokeWidth 0
shape20=Ellipse  ([mCalcCoreAniW]/2),([animationH]/2),([mCoreSegH]*6/7) | StrokeWidth 0
shape21=Rectangle ([mCalcCoreAniW]/16),([animationH]/2-([mCoreSegH:/2]-[CoreSegHSep:/2]*3)),([mCalcCoreAniW]*7/8),([mCoreSegH]-[CoreSegHSep:/2]*6) | StrokeWidth 0
shape22=Combine shape18 | Exclude shape19 | Union shape21 | Exclude shape20 
shape23=combine shape4 | Union shape5 | Union shape6 | Union shape7 | Union shape8 | Union shape9 | Union shape10 | Union shape11 | Union shape12 | Union shape13

[GraphBG]
shape=Line ([GraphCalcX]/10),0,([GraphCalcX]/10),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
Shape2=Line ([GraphCalcX]/10*2),0,([GraphCalcX]/10*2),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape3=Line ([GraphCalcX]/10*3),0,([GraphCalcX]/10*3),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
Shape4=Line ([GraphCalcX]/10*4),0,([GraphCalcX]/10*4),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape5=Line ([GraphCalcX]/10*5),0,([GraphCalcX]/10*5),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape6=Line ([GraphCalcX]/10*6),0,([GraphCalcX]/10*6),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape7=Line ([GraphCalcX]/10*7),0,([GraphCalcX]/10*7),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape8=Line ([GraphCalcX]/10*8),0,([GraphCalcX]/10*8),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape9=Line ([GraphCalcX]/10*9),0,([GraphCalcX]/10*9),([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette6#
shape10=Line 0,(([GraphCalcX]/10)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10)),[GraphCalcX],(([GraphCalcX]/10)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10)) | StrokeWidth 1 | StrokeColor #Palette6#
shape11=Line 0,(([GraphCalcX]/10*2)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*2)),[GraphCalcX],(([GraphCalcX]/10*2)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*2)) | StrokeWidth 1 | StrokeColor #Palette6#
shape12=Line 0,(([GraphCalcX]/10*3)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*3)),[GraphCalcX],(([GraphCalcX]/10*3)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*3)) | StrokeWidth 1 | StrokeColor #Palette6#
shape13=Line 0,(([GraphCalcX]/10*4)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*4)),[GraphCalcX],(([GraphCalcX]/10*4)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*4)) | StrokeWidth 1 | StrokeColor #Palette6#
shape14=Line 0,(([GraphCalcX]/10*5)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*5)),[GraphCalcX],(([GraphCalcX]/10*5)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*5)) | StrokeWidth 1 | StrokeColor #Palette6#
shape15=Line 0,(([GraphCalcX]/10*6)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*6)),[GraphCalcX],(([GraphCalcX]/10*6)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*6)) | StrokeWidth 1 | StrokeColor #Palette6#
shape16=Line 0,(([GraphCalcX]/10*7)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*7)),[GraphCalcX],(([GraphCalcX]/10*7)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*7)) | StrokeWidth 1 | StrokeColor #Palette6#
shape17=Line 0,(([GraphCalcX]/10*8)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*8)),[GraphCalcX],(([GraphCalcX]/10*8)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*8)) | StrokeWidth 1 | StrokeColor #Palette6#
shape18=Line 0,(([GraphCalcX]/10*9)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*9)),[GraphCalcX],(([GraphCalcX]/10*9)>[GraphCalcY]?[GraphCalcY]:([GraphCalcX]/10*9)) | StrokeWidth 1 | StrokeColor #Palette6#
shape19=Rectangle 0,0,[GraphCalcX],([GraphCalcY]) | StrokeWidth 1 | StrokeColor #Palette4# | Fill Color 00000000

[MemGraphBG]
shape=Line ([#CurrentSection#:W]/10),0,([#CurrentSection#:W]/10),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
Shape2=Line ([#CurrentSection#:W]/10*2),0,([#CurrentSection#:W]/10*2),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape3=Line ([#CurrentSection#:W]/10*3),0,([#CurrentSection#:W]/10*3),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
Shape4=Line ([#CurrentSection#:W]/10*4),0,([#CurrentSection#:W]/10*4),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape5=Line ([#CurrentSection#:W]/10*5),0,([#CurrentSection#:W]/10*5),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape6=Line ([#CurrentSection#:W]/10*6),0,([#CurrentSection#:W]/10*6),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape7=Line ([#CurrentSection#:W]/10*7),0,([#CurrentSection#:W]/10*7),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape8=Line ([#CurrentSection#:W]/10*8),0,([#CurrentSection#:W]/10*8),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape9=Line ([#CurrentSection#:W]/10*9),0,([#CurrentSection#:W]/10*9),[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette6#
shape10=Line 0,([#CurrentSection#:W]/10),[#CurrentSection#:W],([#CurrentSection#:W]/10) | StrokeWidth 1 | StrokeColor #Palette6#
shape11=Line 0,([#CurrentSection#:W]/10*2),[#CurrentSection#:W],([#CurrentSection#:W]/10*2) | StrokeWidth 1 | StrokeColor #Palette6#
shape12=Line 0,([#CurrentSection#:W]/10*3),[#CurrentSection#:W],([#CurrentSection#:W]/10*3) | StrokeWidth 1 | StrokeColor #Palette6#
shape13=Line 0,([#CurrentSection#:W]/10*4),[#CurrentSection#:W],([#CurrentSection#:W]/10*4) | StrokeWidth 1 | StrokeColor #Palette6#
shape14=Rectangle 0,0,[#CurrentSection#:W],[#CurrentSection#:H] | StrokeWidth 1 | StrokeColor #Palette4# | Fill Color 00000000

[CpuBarGraph]
shape=Rectangle 85,([#CurrentSection#:H]/10),([PerecentMaxCPUspeed]/110*([#CurrentSection#:W]-87)),([#CurrentSection#:H]/10*3.5) | StrokeWidth 0 | Fill Color #Palette1#
shape2=Rectangle 85,([#CurrentSection#:H]/10*5.5+2),([CPUpercent]/100*([#CurrentSection#:W]-87)),([#CurrentSection#:H]/10*3.5) | StrokeWidth 0 | Fill Color #Palette2#
VerticleBarCap=0,36 | CurveTo 36,0,0,0 | LineTo 83,0 | LineTo 83,[#CurrentSection#:H] | LineTo 36,[#CurrentSection#:H] | CurveTo 0,([#CurrentSection#:H]-36),0,[#CurrentSection#:H] | ClosePath 1
VerticleBarGraph=85,2 | LineTo ([#CurrentSection#:W]-12),2 | CurveTo ([#CurrentSection#:W]-2),12,[#CurrentSection#:W],0 | LineTo ([#CurrentSection#:W]-2),([#CurrentSection#:H]-12) | CurveTo ([#CurrentSection#:W]-12),([#CurrentSection#:H]-2),[#CurrentSection#:W],[#CurrentSection#:H] | LineTo 85,([#CurrentSection#:H]-2) | ClosePath 1
Markers=StrokeWidth 2 | StrokeColor #Palette4#
Shape3=Path VerticleBarCap | StrokeWidth 0 | Fill Color #Palette4#
shape4=Path VerticleBarGraph | StrokeWidth 4 | Fill Color 00000000 | StrokeColor #Palette4#
shape5=Line (([#CurrentSection#:W]-85)/10+85),0,(([#CurrentSection#:W]-85)/10+85),([#CurrentSection#:H]/4) | Extend Markers
shape6=Line (([#CurrentSection#:W]-85)/10*2+85),0,(([#CurrentSection#:W]-85)/10*2+85),([#CurrentSection#:H]/4) | Extend Markers
shape7=Line (([#CurrentSection#:W]-85)/10*3+85),0,(([#CurrentSection#:W]-85)/10*3+85),([#CurrentSection#:H]/4) | Extend Markers
shape8=Line (([#CurrentSection#:W]-85)/10*4+85),0,(([#CurrentSection#:W]-85)/10*4+85),([#CurrentSection#:H]/4) | Extend Markers
shape9=Line (([#CurrentSection#:W]-85)/10*5+85),0,(([#CurrentSection#:W]-85)/10*5+85),([#CurrentSection#:H]/4) | Extend Markers
shape10=Line (([#CurrentSection#:W]-85)/10*6+85),0,(([#CurrentSection#:W]-85)/10*6+85),([#CurrentSection#:H]/4) | Extend Markers
shape11=Line (([#CurrentSection#:W]-85)/10*7+85),0,(([#CurrentSection#:W]-85)/10*7+85),([#CurrentSection#:H]/4) | Extend Markers
shape12=Line (([#CurrentSection#:W]-85)/10*8+85),0,(([#CurrentSection#:W]-85)/10*8+85),([#CurrentSection#:H]/4) | Extend Markers
shape13=Line (([#CurrentSection#:W]-85)/10*9+85),0,(([#CurrentSection#:W]-85)/10*9+85),([#CurrentSection#:H]/4) | Extend Markers
shape14=Line (([#CurrentSection#:W]-85)/10+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10+85),([#CurrentSection#:H]) | Extend Markers
shape15=Line (([#CurrentSection#:W]-85)/10*2+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*2+85),([#CurrentSection#:H]) | Extend Markers
shape16=Line (([#CurrentSection#:W]-85)/10*3+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*3+85),([#CurrentSection#:H]) | Extend Markers
shape17=Line (([#CurrentSection#:W]-85)/10*4+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*4+85),([#CurrentSection#:H]) | Extend Markers
shape18=Line (([#CurrentSection#:W]-85)/10*5+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*5+85),([#CurrentSection#:H]) | Extend Markers
shape19=Line (([#CurrentSection#:W]-85)/10*6+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*6+85),([#CurrentSection#:H]) | Extend Markers
shape20=Line (([#CurrentSection#:W]-85)/10*7+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*7+85),([#CurrentSection#:H]) | Extend Markers
shape21=Line (([#CurrentSection#:W]-85)/10*8+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*8+85),([#CurrentSection#:H]) | Extend Markers
shape22=Line (([#CurrentSection#:W]-85)/10*9+85),([#CurrentSection#:H]*3/4),(([#CurrentSection#:W]-85)/10*9+85),([#CurrentSection#:H]) | Extend Markers

[AudioSpectrumGraphBG]
BgLines=StrokeWidth 1 | StrokeColor #Palette5#
shape=Rectangle 0,0,([#CurrentSection#:W]),([#CurrentSection#:H]),([#CurrentSection#:H]/(#WorkAreaWidth#>#WorkAreaHeight#?20:10)) | StrokeWidth 2 | StrokeColor #Palette4# | Fill Color 0,0,0,1
shape2=Line 0,([#CurrentSection#:H]/20),[#CurrentSection#:W],([#CurrentSection#:H]/20) | Extend BgLines
shape3=Line 0,(([#CurrentSection#:H]/20)*2),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*2) | Extend BgLines
shape4=Line 0,(([#CurrentSection#:H]/20)*3),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*3) | Extend BgLines
shape5=Line 0,(([#CurrentSection#:H]/20)*4),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*4) | Extend BgLines
shape6=Line 0,(([#CurrentSection#:H]/20)*5),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*5) | Extend BgLines
shape7=Line 0,(([#CurrentSection#:H]/20)*6),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*6) | Extend BgLines
shape8=Line 0,(([#CurrentSection#:H]/20)*7),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*7) | Extend BgLines
shape9=Line 0,(([#CurrentSection#:H]/20)*8),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*8) | Extend BgLines
shape10=Line 0,(([#CurrentSection#:H]/20)*9),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*9) | Extend BgLines
shape11=Line 0,(([#CurrentSection#:H]/20)*11),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*11) | Extend BgLines
shape12=Line 0,(([#CurrentSection#:H]/20)*12),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*12) | Extend BgLines
shape13=Line 0,(([#CurrentSection#:H]/20)*13),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*13) | Extend BgLines
shape14=Line 0,(([#CurrentSection#:H]/20)*14),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*14) | Extend BgLines
shape15=Line 0,(([#CurrentSection#:H]/20)*15),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*15) | Extend BgLines
shape16=Line 0,(([#CurrentSection#:H]/20)*16),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*16) | Extend BgLines
shape17=Line 0,(([#CurrentSection#:H]/20)*17),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*17) | Extend BgLines
shape18=Line 0,(([#CurrentSection#:H]/20)*18),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*18) | Extend BgLines
shape19=Line 0,(([#CurrentSection#:H]/20)*19),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*19) | Extend BgLines

[CurveAudio]
curves=StrokeWidth 3 | StrokeColor #Palette2# | fill Color #Palette3#
curvyAudio=2,([#CurrentSection#:H]/2) | LineTo (([#CurrentSection#:W]/21)*0.5),([#CurrentSection#:H]/2) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*1.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)),(([#CurrentSection#:H]/2)-([mBand0]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*2.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*2),(([#CurrentSection#:H]/2)+([mBand1]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*3.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*3),(([#CurrentSection#:H]/2)-([mBand2]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*4.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*4),(([#CurrentSection#:H]/2)+([mBand3]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*5.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*5),(([#CurrentSection#:H]/2)-([mBand4]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*6.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*6),(([#CurrentSection#:H]/2)+([mBand5]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*7.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*7),(([#CurrentSection#:H]/2)-([mBand6]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*8.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*8),(([#CurrentSection#:H]/2)+([mBand7]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*9.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*9),(([#CurrentSection#:H]/2)-([mBand8]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*10.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*10),(([#CurrentSection#:H]/2)+([mBand9]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*11.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*11),(([#CurrentSection#:H]/2)-([mBand10]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*12.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*12),(([#CurrentSection#:H]/2)+([mBand11]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*13.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*13),(([#CurrentSection#:H]/2)-([mBand12]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*14.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*14),(([#CurrentSection#:H]/2)+([mBand13]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*15.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*15),(([#CurrentSection#:H]/2)-([mBand14]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*16.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*16),(([#CurrentSection#:H]/2)+([mBand15]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*17.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*17),(([#CurrentSection#:H]/2)-([mBand16]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*18.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*18),(([#CurrentSection#:H]/2)+([mBand17]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*19.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*19),(([#CurrentSection#:H]/2)-([mBand18]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*20.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*20),(([#CurrentSection#:H]/2)+([mBand19]*[#CurrentSection#:H])) | LineTo ([#CurrentSection#:W]-2),([#CurrentSection#:H]/2) | closePath 1
curvyAudio2=2,([#CurrentSection#:H]/2) | LineTo (([#CurrentSection#:W]/21)*0.5),([#CurrentSection#:H]/2) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*1.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)),(([#CurrentSection#:H]/2)+([mBand0]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*2.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*2),(([#CurrentSection#:H]/2)-([mBand1]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*3.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*3),(([#CurrentSection#:H]/2)+([mBand2]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*4.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*4),(([#CurrentSection#:H]/2)-([mBand3]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*5.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*5),(([#CurrentSection#:H]/2)+([mBand4]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*6.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*6),(([#CurrentSection#:H]/2)-([mBand5]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*7.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*7),(([#CurrentSection#:H]/2)+([mBand6]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*8.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*8),(([#CurrentSection#:H]/2)-([mBand7]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*9.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*9),(([#CurrentSection#:H]/2)+([mBand8]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*10.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*10),(([#CurrentSection#:H]/2)-([mBand9]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*11.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*11),(([#CurrentSection#:H]/2)+([mBand10]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*12.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*12),(([#CurrentSection#:H]/2)-([mBand11]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*13.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*13),(([#CurrentSection#:H]/2)+([mBand12]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*14.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*14),(([#CurrentSection#:H]/2)-([mBand13]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*15.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*15),(([#CurrentSection#:H]/2)+([mBand14]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*16.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*16),(([#CurrentSection#:H]/2)-([mBand15]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*17.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*17),(([#CurrentSection#:H]/2)+([mBand16]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*18.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*18),(([#CurrentSection#:H]/2)-([mBand17]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*19.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*19),(([#CurrentSection#:H]/2)+([mBand18]*[#CurrentSection#:H])) | setRoundJoin 1 | CurveTo (([#CurrentSection#:W]/21)*20.5),([#CurrentSection#:H]/2),(([#CurrentSection#:W]/21)*20),(([#CurrentSection#:H]/2)-([mBand19]*[#CurrentSection#:H])) | LineTo ([#CurrentSection#:W]-2),([#CurrentSection#:H]/2) | closePath 1
shape=path curvyAudio | extend curves
shape2=path curvyAudio2 | extend curves

[BarAudio]
BarAttribute=StrokeWidth 2 | StrokeColor #Palette2# | fill Color #Palette3#
shape=Line 0,(([#CurrentSection#:H]/20)*10),[#CurrentSection#:W],(([#CurrentSection#:H]/20)*10) | StrokeWidth 2 | StrokeColor #Palette2#
shape2=Rectangle 13,((1-[mBand0])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand0]*[#CurrentSection#:H]) | Extend BarAttribute
shape3=Rectangle 13,((1-[mBand1])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand1]*[#CurrentSection#:H]) | Extend BarAttribute | offset ([mCalcAudioSeg]+13),0
shape4=Rectangle 13,((1-[mBand2])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand2]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*2),0
shape5=Rectangle 13,((1-[mBand3])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand3]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*3),0
shape6=Rectangle 13,((1-[mBand4])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand4]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*4),0
shape7=Rectangle 13,((1-[mBand5])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand5]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*5),0
shape8=Rectangle 13,((1-[mBand6])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand6]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*6),0
shape9=Rectangle 13,((1-[mBand7])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand7]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*7),0
shape10=Rectangle 13,((1-[mBand8])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand8]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*8),0
shape11=Rectangle 13,((1-[mBand9])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand9]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*9),0
shape12=Rectangle 13,((1-[mBand10])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand10]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*10),0
shape13=Rectangle 13,((1-[mBand11])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand11]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*11),0
shape14=Rectangle 13,((1-[mBand12])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand12]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*12),0
shape15=Rectangle 13,((1-[mBand13])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand13]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*13),0
shape16=Rectangle 13,((1-[mBand14])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand14]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*14),0
shape17=Rectangle 13,((1-[mBand15])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand15]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*15),0
shape18=Rectangle 13,((1-[mBand16])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand16]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*16),0
shape19=Rectangle 13,((1-[mBand17])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand17]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*17),0
shape20=Rectangle 13,((1-[mBand18])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand18]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*18),0
shape21=Rectangle 13,((1-[mBand19])*([#CurrentSection#:H]/2)),([mCalcAudioSeg]),([mBand19]*[#CurrentSection#:H]) | Extend BarAttribute | offset (([mCalcAudioSeg]+13)*19),0

[VertBarGraph]
TopCap=0,36 | CurveTo 36,0,0,0 | LineTo 94,0 | CurveTo 130,36,130,0 | ClosePath 1
BottomCap=0,([#CurrentSection#:H]-36) | CurveTo 36,[#CurrentSection#:H],0,[#CurrentSection#:H] | LineTo 94,[#CurrentSection#:H] | CurveTo 130,([#CurrentSection#:H]-36),130,[#CurrentSection#:H] | ClosePath 1
LineAttribute=StrokeWidth 2 | StrokeColor #Palette3#
shape2=Path TopCap | StrokeWidth 0 | Fill Color #Palette3#
shape3=Rectangle 1,36,128,([#CurrentSection#:H]-72) | Extend LineAttribute | Fill Color 0,0,0,1
shape4=Path BottomCap | StrokeWidth 0 | Fill Color #Palette3#
shape5=Line 0,(([#CurrentSection#:H]-72)*0.1+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.1+37) | Extend LineAttribute
shape6=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.1+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.1+37) | Extend LineAttribute
shape7=Line 0,(([#CurrentSection#:H]-72)*0.2+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.2+37) | Extend LineAttribute
shape8=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.2+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.2+37) | Extend LineAttribute
shape9=Line 0,(([#CurrentSection#:H]-72)*0.3+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.3+37) | Extend LineAttribute
shape10=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.3+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.3+37) | Extend LineAttribute
shape11=Line 0,(([#CurrentSection#:H]-72)*0.4+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.4+37) | Extend LineAttribute
shape12=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.4+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.4+37) | Extend LineAttribute
shape13=Line 0,(([#CurrentSection#:H]-72)*0.5+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.5+37) | Extend LineAttribute
shape14=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.5+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.5+37) | Extend LineAttribute
shape15=Line 0,(([#CurrentSection#:H]-72)*0.6+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.6+37) | Extend LineAttribute
shape16=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.6+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.6+37) | Extend LineAttribute
shape17=Line 0,(([#CurrentSection#:H]-72)*0.7+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.7+37) | Extend LineAttribute
shape18=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.7+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.7+37) | Extend LineAttribute
shape19=Line 0,(([#CurrentSection#:H]-72)*0.8+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.8+37) | Extend LineAttribute
shape20=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.8+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.8+37) | Extend LineAttribute
shape21=Line 0,(([#CurrentSection#:H]-72)*0.9+37),([#CurrentSection#:W]/4),(([#CurrentSection#:H]-72)*0.9+37) | Extend LineAttribute
shape22=Line ([#CurrentSection#:W]*3/4),(([#CurrentSection#:H]-72)*0.9+37),([#CurrentSection#:W]),(([#CurrentSection#:H]-72)*0.9+37) | Extend LineAttribute

[scanner]
TrackCenter=([transitX]-[#currentSection#:W]/2),([transitY]-[#currentSection#:H]/2),0,0,([#currentSection#:H]),([#currentSection#:H]) | #Palette7# ; 0.1 | #Palette7#,1 ; 1
BgLines=StrokeWidth (([#currentSection#:W]+[#currentSection#:H])/2*0.003) | StrokeColor #Palette5#
crosshairs=StrokeWidth (([#currentSection#:W]+[#currentSection#:H])/2*0.004) | StrokeColor #Palette2#
shape=Rectangle (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.02)),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.02)),(([#currentSection#:W]+[#currentSection#:H])/2*0.008) | StrokeWidth 0 | Fill RadialGradient TrackCenter
shape2=Line ([transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend crosshairs
shape3=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitY]),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),([transitY]) | Extend crosshairs
shape4=Line ([transitX]/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape5=Line ([transitX]*2/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]*2/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape6=Line ([transitX]*3/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]*3/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape7=Line ([transitX]*4/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]*4/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape8=Line ([transitX]*5/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]*5/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape9=Line ([transitX]*6/7),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitX]*6/7),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape10=Line (([#currentSection#:W]-[transitX])/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape11=Line (([#currentSection#:W]-[transitX])*2/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])*2/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape12=Line (([#currentSection#:W]-[transitX])*3/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])*3/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape13=Line (([#currentSection#:W]-[transitX])*4/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])*4/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape14=Line (([#currentSection#:W]-[transitX])*5/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])*5/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape15=Line (([#currentSection#:W]-[transitX])*6/7+[transitX]),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]-[transitX])*6/7+[transitX]),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)) | Extend BgLines
shape16=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitY]/5),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),([transitY]/5) | Extend BgLines
shape17=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitY]*2/5),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),([transitY]*2/5) | Extend BgLines
shape18=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitY]*3/5),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),([transitY]*3/5) | Extend BgLines
shape19=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),([transitY]*4/5),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),([transitY]*4/5) | Extend BgLines
shape20=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:H]-[transitY])/5+[transitY]),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),(([#currentSection#:H]-[transitY])/5+[transitY]) | Extend BgLines
shape21=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:H]-[transitY])*2/5+[transitY]),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),(([#currentSection#:H]-[transitY])*2/5+[transitY]) | Extend BgLines
shape22=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:H]-[transitY])*3/5+[transitY]),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),(([#currentSection#:H]-[transitY])*3/5+[transitY]) | Extend BgLines
shape23=Line (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:H]-[transitY])*4/5+[transitY]),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.01)),(([#currentSection#:H]-[transitY])*4/5+[transitY]) | Extend BgLines
shape24=Rectangle (([#currentSection#:W]+[#currentSection#:H])/2*0.01),(([#currentSection#:W]+[#currentSection#:H])/2*0.01),([#currentSection#:W]-(([#currentSection#:W]+[#currentSection#:H])/2*0.02)),([#currentSection#:H]-(([#currentSection#:W]+[#currentSection#:H])/2*0.02)),(([#currentSection#:W]+[#currentSection#:H])/2*0.008) | StrokeWidth (([#currentSection#:W]+[#currentSection#:H])/2*0.02) | StrokeColor #Palette6# | Fill Color 00000000
