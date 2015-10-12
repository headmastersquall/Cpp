(defn multiply [x y]
  (loop [a x, b y, prod y]
    (if (= a 0)
      prod
      (recur (dec a) b (+ prod b)))))

(println (str "4 * 66 = " (multiply 4 66)))

