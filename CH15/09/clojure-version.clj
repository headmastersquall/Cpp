(ns fun.core
  (require [clojure.java.io :refer [reader writer]]
           [clojure.string :refer [upper-case]])
  (:gen-class))

(defn copy-file
  "Copy the content of the first file to the second file while
   applying a transformation function on each line"
  [from to transformation]
  (with-open [r (reader from)
              w (writer to)]
    (binding [*out* w]
      (doseq [line (line-seq r)]
        (println (transformation line))))))

(defn id
  "Return the value with no change"
  [s] s)

(defn to-upper
  "Convert the provided string to upper case"
  [s]
  (upper-case s))

(defn encrypt
  "Add the provided integer value to each character in the string"
  [i s]
  (->> (char-array s)
       (map byte)
       (map #(+ i %))
       (map char)
       (apply str)))

(defn -main []
  (let [src "/home/squall/test.txt"
        dest-id "/home/squall/test-id.txt"
        dest-upper "/home/squall/test-upper.txt"
        dest-encrypt "/home/squall/test-encrypt.txt"]
    (copy-file src dest-id id)
    (copy-file src dest-upper to-upper)
    (copy-file src dest-encrypt (partial encrypt 17))))
