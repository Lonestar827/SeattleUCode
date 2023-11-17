(*Author: Jared Callero
Program: hw4.fsx
*)


type BST =
    | Empty
    | TreeNode of int * BST * BST


let rec insert value tree =
    (*insert(value, tree): 
    Inserts the user inputed value into the BST. if the value is nothing returns the unaltered tree.
    Otherwise it traverses the tree, inserts the value, and returns the altered tree.
    *)
    
    match tree with
    //if value == null then return tree(value)
    |Empty -> TreeNode (value,Empty,Empty)

    //if value < nodeValue, traverse left then print current node
    |TreeNode(nodeValue, left, right) when value < nodeValue->
        let newLeft = insert value left
        TreeNode (nodeValue, newLeft, right)
    
    //if value > nodeValue, traverse right then print current node
    |TreeNode(nodeValue, left, right) when value > nodeValue->
        let newRight = insert value right
        TreeNode(nodeValue, left, newRight)

    //Else (value is equal), simply return the tree unchanged
    | _ -> tree


let rec search value tree =
    (*search(value, tree):
    searches the tree for the user inputed value. if the value is found, return true.
    Else returns false
    *)

    match tree with
    //if value == null then return false
    |Empty -> false
    
    //if value < tree[0] then search (value tree[1])
    |TreeNode(nodeValue, left, right) when value < nodeValue->
        search value left

    //if value > tree[0] then search (value tree[2])
    |TreeNode(nodeValue, left, right) when value > nodeValue->
        search value right

    //if value == tree[0] then return true
    | _ -> true


let rec count func tree =
    (*count(func, tree): *)
    
    match tree with
    
    |Empty -> 0
    |TreeNode(nodeValue, left, right) ->
        let result = count func left + count func right + func nodeValue
        result
    
    

let evenCount tree =
    //if tree[0] % 2 == 0 then return true else return false

    count (fun x -> (x + 1) % 2) tree


let elimDuplicates userInput= 
    (*elimDuplicated(list:userInput):
    takes in a user inputed list and removes any duplicated values
    *)
    
    //nested recursion that inputs result and current Input

    let rec loop acc = function
        |[] -> acc
        |hd::tl->
            if tl.Length = 0 then loop (hd :: acc) tl
            else if hd <> tl.[0] then loop (hd::acc) tl else loop (acc) tl
            
    
    loop [] userInput
        

let rec maxCylinderVolume array = 
    (*maxCylinderVolume(array):
    takes in an array and finds the max volume within the array.
    *)

    //maxCylinderVolume(array, 0);;
    findMaxCylinderVolume array 0.0;;


let rec findMaxCylinderVolume array maxVolume = 
    (*findMaxCylinderVolume(array, maxVolume): 

    *)
    match array with
    |[] -> maxVolume
    |hd::tl ->
        let r, h = hd
        let newMax = r * r * h * System.Math.PI
        match newMax > maxVolume with
        |true -> findMaxCylinderVolume tl newMax 
        |false -> findMaxCylinderVolume tl maxVolume   
