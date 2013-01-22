open List
open Printf

let listlength : int = 1000;;
let tally : int ref = ref 0;;

let rec check_list =
    let rec produce_list (counter : int) : int list =
        if counter > 0
        then (counter - 1)::(produce_list (counter - 1))
        else []
    in
    let list = produce_list listlength
    in
    let check (elt : int) : unit =
        if (elt mod 3 = 0) || (elt mod 5 = 0)
        then tally := !tally + elt
        else ()
    in
    List.iter check list;;

Printf.printf "Sum of list items divisible by 3 and/or 5 in a list of size %d is: %d\n" listlength !tally;;
    
    


