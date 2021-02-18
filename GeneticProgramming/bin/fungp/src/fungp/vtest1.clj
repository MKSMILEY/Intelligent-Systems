(ns fungp.vtest1
  (:use fungp.core)
  (:use fungp.util)
  (:use clojure.pprint))

(def sample-functions
  '[[+ 2]
    [- 2]
    [* 2]
    [fungp.util/abs 1]
    [fungp.util/sdiv 2]
    [inc 1]
    [dec 1]])

(def sample-parameters
    ['x])

(def number-literals
  (map float (range 10)))

(def in-list  '(1 2 3 4 5))
(def out-list '(2 4 6 8 10))

(defn sample-fitness
  [tree]
  (try
    (let [f (compile-tree tree sample-parameters)
          results (map f in-list)]
      (reduce + (map off-by-sq out-list results)))
    (catch Exception e (println e) (println tree))))

(defn sample-report
  [tree fitness]
  (pprint tree)
  (println (str "Error:\t" fitness "\n"))
  (flush))

(defn test-regression1
  [n1 n2]
  (println "\nfungp :: Functional Genetic Programming in Clojure")
  (println "Mike Vollmer, 2012")
  (println (str "Test inputs: " (vec in-list)))
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
