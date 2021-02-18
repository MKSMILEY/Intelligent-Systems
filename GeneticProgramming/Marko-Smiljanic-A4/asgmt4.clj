(ns fungp.asgmt4
  (:use fungp.core)
  (:use fungp.util)
  (:use clojure.pprint))

(def sample-functions
  '[[+ 2]
    [- 2]
    [* 2]
    [inc 1]
    [dec 1]
	[Math/sin 1]
	[Math/cos 1]])

(def sample-parameters
    ['x 'y])

(def number-literals
  (map float (range 10)))

(def in-list1 '(0 1 1     0.5  -1    -1  1    -2  -1    -3   2    3   1   1.25 1.5  1.75 0    -0.25 -0.25 -0.5 -0.5 0.5  2    2    -2))
(def in-list2 '(0 0 1     0.25 -1     0 -1    -1.5 1    -1.5 1.57 0.5 0.5 0.5  0.5  0.5  1.57 1     -1    -0.5 0.5  0.5  3.14 7.85 7.85))
(def out-list '(0 0 4.21 -1.23 -4.21  0 -4.21 -5   4.21 -5   5    2.4 2.4 0    -2.4 0    5    0     -4.08 -2.4 -2.4 -2.4 0    5    5))


(defn sample-fitness
  [tree]
  (try
    (let [f (compile-tree tree sample-parameters)
          results (map f in-list1 in-list2)]
      (reduce + (map off-by-sq out-list results)))
    (catch Exception e (println e) (println tree))))

(defn sample-report
  [tree fitness]
  (pprint tree)
  (println (str "Error:\t" fitness "\n"))
  (flush))

(defn test-regression3
  [n1 n2]
  (println "\nfungp :: Functional Genetic Programming in Clojure")
  (println "Mike Vollmer, 2012")
  (println (str "Test inputs: " (vec in-list1)))
  (println (str "Test inputs: " (vec in-list2)))
  (println (str "Test outputs: " (vec out-list)))
  (println (str "Max generations: " (* n1 n2)))
  (println)
  (let [options {:iterations n1
                 :migrations n2
                 :num-islands 6
                 :population-size 40
                 :tournament-size 5
                 :mutation-probability 0.1
                 :max-depth 10
                 :terminals sample-parameters
                 :numbers number-literals
                 :fitness sample-fitness
                 :functions sample-functions
                 :report sample-report }
        [tree score] (rest (run-genetic-programming options))]
    (do (println "Done!")
        (sample-report tree score))))
