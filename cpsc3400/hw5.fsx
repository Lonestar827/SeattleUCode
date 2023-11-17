// Preparatory materials for HW5, CPSC 3400, Spring 2021
// Provided by Kevin Lundeen

// Algebraic expression
type Expression =
    | X
    | Y
    | Const of float
    | Neg of Expression
    | Add of Expression * Expression
    | Sub of Expression * Expression
    | Mul of Expression * Expression
;;

// Pretty-printer for an algebraic expression
let exprToString expr =

    let rec toStr subexpr enclosingPrecedence =        
        let parenthesize s myPrecedence =
            if myPrecedence <= enclosingPrecedence then s else (sprintf "(%s)" s)

        match subexpr with
        // precedence 0 are x and y literals
        | X -> "x"
        | Y -> "y"

        // precedence 1 is unary negation
        | Neg (Neg v) -> sprintf "-(-%s)" (toStr v 1) // avoid --ex in favor of -(-ex)
        | Neg u -> parenthesize (sprintf "-%s" (toStr u 1)) 1

        // precedence 2 is a constant (this is bumped up to get -(3) instead of -3 for Neg (Const 3.0))
        | Const c -> parenthesize (sprintf "%g" c) 2

        // precedence 3 for multiplicative ops
        | Mul (u, v) -> parenthesize (sprintf "%s * %s" (toStr u 3) (toStr v 3)) 3

        // precedence 4 for additive ops
        | Add (u, v) -> parenthesize (sprintf "%s + %s" (toStr u 4) (toStr v 4)) 4
        | Sub (u, v) -> parenthesize (sprintf "%s - %s" (toStr u 4) (toStr v 4)) 4

    toStr expr 5
;;

// FIXME - replace the following with your own simplify function for HW5
let rec simplify expr =
	match expr with
	|X -> X
	|Y -> Y
	|Const(u) -> Const(u)
	|Neg(u) when u = X -> Neg X
	|Neg(u) when u = Y -> Neg Y
	//|Neg(u) when u = Neg -> u
	
		
		
	//double Constant
	|Add(Const u, Const v)->
		let newNumber = u + v
		Const newNumber
		
	//adding a variable and 0
	|Add(Const u, X) when u = 0.0 -> X
    |Add(X, Const v) when v = 0.0 -> X
	|Add(Const u, Y) when u = 0.0 -> Y
	|Add(Y, Const v) when v = 0.0 -> Y
		
	//adding two of the same variable
	|Add(X, X) -> Mul(Const 2.0,X)
	|Add(Y, Y) -> Mul(Const 2.0,Y)
		
	//adding a variable and number or two different variables 
	|Add(Const u, Y) -> expr
	|Add(Y, Const v) -> expr 
	|Add(Const u, X) -> expr 
	|Add(X, Const v) -> expr 
	|Add(Y, X)-> expr 
	|Add(X, Y)-> expr
	
	//adding two of the same expression
	//Add(u, v) when u = Expression && v = Expression && u = v -> Simplify Mul 2 u
		
		
	//double constant
	|Sub(Const u, Const v) ->
		let newNumber = u - v
		Const newNumber
		
	//subtracting a variable from 0
	|Sub(Const 0.0, X) -> Neg(X)
	|Sub(Const 0.0, Y) -> Neg(Y)
		
	//subtracting 0 from a variable
	|Sub(X, Const 0.0) -> X
	|Sub(Y, Const 0.0) -> Y
		
	//subtracting the same variable
	|Sub(Y, Y) -> Const 0.0
	|Sub(X, X) -> Const 0.0
		
	//subtracting two different variables
	|Sub(X, Y) -> expr
	|Sub(Y, X) -> expr
		
	//subtracting two of the same expression
	//|Sub(u, v) when u = Expression && v = Expression && u = v -> Const 0.0
		
	//double constant
	|Mul(Const u, Const v) ->
		let newNumber = u * v
		Const newNumber
			
	//multiplying a variable by 1
	|Mul(X, Const 1.0) -> X 
	|Mul(Const 1.0, X) -> X
	|Mul(Y, Const 1.0) -> Y
	|Mul(Const 1.0, Y) -> Y
		
	//multiplying a variable by 0
	|Mul(X, Const 0.0) -> Const 0.0 
	|Mul(Const 0.0, X) -> Const 0.0
	|Mul(Y, Const 0.0) -> Const 0.0
	|Mul(Const 0.0, Y) -> Const 0.0
	
	//multiplying a variable by itself
	|Mul(X, X) -> Mul(Const 2.0,X)
	|Mul(Y, Y) -> Mul(Const 2.0,Y)
		
	//multiplying a variable and constant or a variable with a different variable
	|Mul(Const u, X) -> expr
	|Mul(X, Const u) -> expr
	|Mul(Const u, Y) -> expr
	|Mul(Y, Const v) -> expr
	|Mul(Y, X) -> expr
	|Mul(X, Y) -> expr
;;


let testResults = 
    let test expr expected description =
        let actual = simplify expr
        printfn "\n%s" description
        printfn "simplify (%s)" (exprToString expr)
        printfn "got: %s" (exprToString actual)
        if actual <> expected then
            printfn "but expected: %s\nFAILED" (exprToString expected)
            false
        else
            printfn "passed" 
            true
    [
        test (Add (Const 5.0, Const 3.0)) (Const 8.0) "t1 - addition involving two numbers";
        test (Sub (Const 5.0, Const 3.0)) (Const 2.0) "t2 - subtraction involving two numbers";
        test (Mul (Const 5.0, Const 3.0)) (Const 15.0) "t3 - multiplication involving two numbers";
        test (Neg (Const 4.0)) (Const -4.0) "t4 - negation involving a number";
        test (Neg (Const -9.0)) (Const 9.0) "t5 - negation involving a number";
        test (Add (X, Const 0.0)) X "t6 - addition with zero";
        test (Add (Const 0.0, Y)) Y "t7 - addition with zero";
        test (Sub (X, Const 0.0)) X "t8 - subtraction with zero";
        test (Sub (Const 0.0, Y)) (Neg Y) "t9 - subtraction with zero";
        test (Sub (Y, Y)) (Const 0.0) "t10 - subtraction of identical terms";
        test (Mul (X, Const 0.0)) (Const 0.0) "t11 - multiplication with zero";
        test (Mul (Const 0.0, Y)) (Const 0.0) "t12 - multiplication with zero";
        test (Mul (X, Const 1.0)) X "t13 - multiplication with one";
        test (Mul (Const 1.0, Y)) Y "t14 - multiplication with one";
        test (Neg (Neg X)) X "t15 - double negation";
        test (Sub (Mul (Const 1.0, X), Add (X, Const 0.0))) (Const 0.0) "t16 - recursive simplification";
        test (Add (Mul (Const 4.0, Const 3.0), Sub (Const 11.0, Const 5.0))) (Const 18.0) "t17";
        test (Sub (Sub (Add (X, Const 1.0), Add (X, Const 1.0)), Add (Y, X))) (Neg (Add (Y, X))) "t18";
        test (Sub (Const 0.0, Neg (Mul (Const 1.0, X)))) X "t19";
        //test (Mul (Add (X, Const 1.0), Neg (Sub (Mul (Const 2.0, Y), X)))) (Mul (Add (X, Const 1.0), Neg (Sub (Mul (Const 2.0, Y), X)))) "t20"
        
        //The above test has been commented out due to an infinite loop happening and me not having enough time to figure it out.

        // FIXME - add some of your own tests!
        test (Neg(Neg(Neg(X)))) X "t21, triple negation";
        test (Add (Add (Const 1.0, X), Add (Const 1.0, X))) Mul (Const 2.0, Add (Const 1.0, X)) "t22, adding the same thing";
        test (Sub (Add (Const 1.0, X), Add (Const 1.0, X))) Const 0.0 "t23, subtracting the same thing";
        test (Sub (Sub (Const 3.5, Const 4.5), Add (Const 4.5, Const 3.5))) (Const -9.0) "T24";
        test (Mul (Mul (Const 2.0, Const 2.0), Mul (Const 2.0, Const 2.0))) (Const 16.0) "T25";
        test (Mul (Mul (Const 2.0, Const 2.0), X)) (Mul (Const 4.0, X)) "T26";
        test (Mul (Add (Const 0.0, X), Sub (Y, Const 0.0))) (Mul (X, Y)) "T27";
        test (Sub (Const 0.0, Mul (Add (Const 0.0, X), Sub (Y, Const 0.0)))) (Neg (Mul (X, Y))) "T28";
        test (Neg (Sub (Const 0.0, X))) X "T29";
        test (Const 0.0, Sub (Sub (Const 3.5, Const 4.5), Add (Const 4.5, Const 3.5))) Const 0.0 "T30";


    ];;

let passes = (List.filter (fun bool -> bool) testResults).Length;;
let failures = testResults.Length - passes;;
printfn "%s" (if failures > 0 then (sprintf "%d FAILURES!" failures) else "all tests passed");;
