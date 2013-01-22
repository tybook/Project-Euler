open List
open Printf

let max_value : int = 4000000;;
let tally : int ref = ref 0;;

let fibo_sum : unit =
  let rec fibo_sequence (input : int list) : int list =
    match input with
      | hd1::hd2::tl ->
          let next : int = hd1 + hd2 in
          if next <= max_value
          then (fibo_sequence (next::input))
          else input
      | _ -> []
  in
  let fibo_list = fibo_sequence [2;1] in
  let fibo_check (elt : int) : unit =
    if elt mod 2 == 0
    then tally := !tally + elt
    else ()
  in
  List.iter fibo_check fibo_list
;;

Printf.printf "Sum of even elts in fibonacci sequence of max %d is: %d\n" max_value !tally;;
