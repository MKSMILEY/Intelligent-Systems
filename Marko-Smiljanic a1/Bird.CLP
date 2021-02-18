(deftemplate Wingspan
	50 250 wingcm
	((Sml (75 1)  (150 0))
	 (Med (75 0)  (150 1) (225 0))
	 (Lrg (150 0) (225 1))))

(deftemplate Length
	30 90 lengthcm
	((Srt (45 1) (60 0))
	 (Mid (45 0) (60 1) (75 0))
	 (Tal (60 0) (75 1))))

(deftemplate Result
	-1 1 size
	((SM (-1 1) (.5 0))
	 (MD (-.5 0) (0 1) (.5 0))
	 (LG (.5 0) (1 1))))

(defrule Get_Observations
	?i <- (initial-fact)
	=>
	(printout t "What is your bird's estimated wingspan?" crlf)
	(printout t "Enter wingspan: ")
	(bind ?response (read))
	(assert (crispWingspan ?response))
	(printout t "What is your bird's estimated length?" crlf)
	(printout t "Enter length: ")
	(bind ?response (read))
	(assert (crispLength ?response))
	(retract ?i))

(defrule fuzzify
	(crispWingspan ?w)
	(crispLength ?l)
	=>
	(assert (Wingspan (?w 0) (?w 1) (?w 0)))
	(assert (Length   (?l 0) (?l 1) (?l 0))))

(defrule defuzzify1
	(declare (salience -1))
	?r <- (Result ?)
	=>
	(bind ?s (maximum-defuzzify ?r))
	(assert (size ?s)))

(defrule SS
	(Wingspan Sml)
	(Length   Srt)
	=>
	(assert (Result SM)))

(defrule SM
	(Wingspan Sml)
	(Length   Mid)
	=>
	(assert (Result SM)))

(defrule ST
	(Wingspan Sml)
	(Length   Tal)
	=>
	(assert (Result MD)))

(defrule MS
	(Wingspan Med)
	(Length   Srt)
	=>
	(assert (Result SM)))

(defrule MM
	(Wingspan Med)
	(Length   Mid)
	=>
	(assert (Result MD)))

(defrule MT
	(Wingspan Med)
	(Length   Tal)
	=>
	(assert (Result LG)))

(defrule LS
	(Wingspan Lrg)
	(Length   Srt)
	=>
	(assert (Result MD)))

(defrule LM
	(Wingspan Lrg)
	(Length   Mid)
	=>
	(assert (Result LG)))

(defrule LT
	(Wingspan Lrg)
	(Length   Tal)
	=>
	(assert (Result LG)))

(defrule p1
	(size ?s)
	(test (> ?s -10))
	=>
	(printout t "In what terrain did you see your bird?" crlf)
	(printout t "(Expected Answers: Lake, River, Coast, Grasslands, Marsh, Mountain, City, Forest)" crlf)
	(printout t "Enter terrain: ")
	(assert (terrain (read))))

(defrule p2
	(size ?s)
	(test (> ?s -10))
	=>
	(printout t "What is the primary color of your bird?" crlf)
	(printout t "(Expected Answers: Brown, White, Black, Gray)" crlf)
	(printout t "Enter Primary Color: ")
	(assert (pColor (read))))

(defrule p3
	(size ?s)
	(test (> ?s -10))
	=>
	(printout t "What is the secondary color of your bird?" crlf)
	(printout t "(Expected Answers: White, Gray, Brown, None)" crlf)
	(printout t "Enter Secondary Color: ")
	(assert (sColor (read)))
	(printout t "Here are a list of birds that you may have found:" crlf))

(defrule baldEagle
	(size ?s)
	(test (> ?s 0.5))
	(or
		(terrain Lake)
		(terrain River)
		(terrain Coast)
		(terrain Marsh))
	(pColor Brown)
	(or
		(sColor None)
		(sColor Black))
	=>
	(printout t "-Bald Eagle" crlf))

(defrule goldenEagle
	(size ?s)
	(test (> ?s 0.5))
	(or
		(terrain Mountain)
		(terrain Grasslands))
	(pColor Brown)
	(sColor None)
	=>
	(printout t "-Golden Eagle" crlf))

(defrule whiteTailedKite
	(size ?s)
	(test (< ?s -0.5))
	(or
		(terrain Grasslands)
		(terrain Marsh))
	(pColor White)
	(or
		(sColor Black)
		(sColor None))
	=>
	(printout t "-White Tailed Kite" crlf))

(defrule calCondor
	(size ?s)
	(test (> ?s 0.5))
	(or
		(terrain Mountain)
		(terrain Coast))
	(pColor Black)
	(sColor White)
	=>
	(printout t "-California Condor" crlf))

(defrule peregrineFalcon
	(size ?s)
	(test (< ?s -0.5))
	(or
		(pColor Gray)
		(pColor Black))
	(sColor White)
	=>
	(printout t "-Peregrine Falcon" crlf))

(defrule swainsonsHawk
	(size ?s)
	(test (< ?s 0.5))
	(terrain Grasslands)
	(or
		(pColor Black)
		(pColor Gray))
	(sColor None)
	=>
	(printout t "-Golden Eagle" crlf))

(defrule spottedOwl
	(size ?s)
	(test (> ?s -0.5))
	(terrain Forest)
	(pColor Brown)
	(or
		(sColor White)
		(sColor Gray)
		(sColor None))
	=>
	(printout t "-Spotted Owl" crlf))
	

(defrule grayOwl
	(size ?s)
	(test (> ?s 0.5))
	(terrain Forest)
	(or
		(pColor Brown)
		(pColor Gray))
	(or
		(sColor White)
		(sColor None))
	=>
	(printout t "-Great Gray Owl" crlf))

(defrule osprey
	(size ?s)
	(test (< ?s 0.5))
	(test (> ?s -0.5))
	(or
		(terrain Coast)
		(terrain River)
		(terrain Lake)
		(terrain Marsh))
	(pColor Brown)
	(sColor White)
	=>
	(printout t "-Osprey" crlf))

(defrule merlin
	(size ?s)
	(test (< ?s -0.5))
	(or
		(terrain City)
		(terrain River)
		(terrain Forest))
	(or
		(pColor Brown)
		(pColor Gray))
	(or
		(sColor White)
		(sColor None))
	=>
	(printout t "-Merlin" crlf))

(defrule redTailedHawk
	(size ?s)
	(test (< ?s 0.5))
	(terrain Grasslands)
	(pColor Brown)
	(or
		(sColor White)
		(sColor None))
	=>
	(printout t "-Red Tailed Hawk" crlf))

(defrule prairieFalcon
	(size ?s)
	(test (< ?s -0.5))
	(terrain Grasslands)
	(pColor Brown)
	(or
		(sColor None)
		(sColor White))
	=>
	(printout t "-Prairie Falcon" crlf))