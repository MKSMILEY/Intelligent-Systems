(defrule p1
	?p <- (start)
	=>
	(printout t "Is it hot or cold outside?")
	(assert (temp (read)))
	(retract ?p))
	
(defrule p2
	(temp hot)
	=>
	(printout t "Do you feel like wearing a tshirt or a tanktop?")
	(assert (shirt (read))))
	
(defrule p3
	(temp hot)
	=>
	(printout t "Is it jeans or shorts weather?")
	(assert (pants (read))))

	
(defrule rule1
	(temp hot)
	(shirt tshirt)
	(pants jeans)
	=>
	(printout t "You are wearing a tshirt and jeans in the hot weather!"))
	
(defrule rule2
	(temp hot)
	(shirt tshirt)
	(pants shorts)
	=>
	(printout t "You are wearing a tshirt and shorts in the hot weather!"))
	
(defrule rule3
	(temp hot)
	(shirt tanktop)
	(pants jeans)
	=>
	(printout t "You are wearing a tanktop and jeans in the hot weather!"))
	
(defrule rule4
	(temp hot)
	(shirt tanktop)
	(pants shorts)
	=>
	(printout t "You are wearing a tanktop and shorts in the hot weather!"))
	
(defrule p4
	(temp cold)
	=>
	(printout t "Is it raining?")
	(assert (rain (read))))
	
(defrule rule5
	(temp cold)
	(rain no)
	=>
	(printout t "You should wear a windbreaker to keep warm in the clear weather!"))
	
(defrule rule6
	(temp cold)
	(rain yes)
	=>
	(printout t "You should wear a jacket and bring an umbrella in the rainy weather!"))
	
(deffacts startup
	(start))
	