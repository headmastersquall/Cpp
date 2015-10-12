(defn sum [nums]
  (loop [s nums total 0]
    (if (seq s)
      (recur (next s) (+ total (first s)))
      total)))

(println (str "The sum is " (sum [1 2 3 4 5 6 7 8 9 10])))