namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current) {
                X(q1);
            }
        }
    }

    operation Test (count : Int, initial0: Result, initial1: Result, initial2: Result) : (Int,Int,Int,Int)
    {
        body
        {
            mutable numOnes = 0;
            mutable agree1 = 0;
            mutable agree2 = 0;
            using (qubits = Qubit[3])
            {
                for (test in 1..count)
                {
                    Set (initial0, qubits[0]);
                    Set (initial1, qubits[1]);
                    Set (initial2, qubits[2]);
    
                    GenerateGHZ(qubits);
                    let res = M (qubits[0]);

                    if (res == M(qubits[1]))
                    {
                        set agree1 = agree1 + 1;
                    }

                    if (res == M(qubits[2]))
                    {
                        set agree2 = agree2 + 1;
                    }

                    // Count the number of ones we saw:
                    if (res == One)
                    {
                        set numOnes = numOnes + 1;
                    }
                }

                Set(Zero, qubits[0]);
                Set(Zero, qubits[1]);
                Set(Zero, qubits[2]);
            }
            // Return number of times we saw a |0> and number of times we saw a |1>
            return (count-numOnes, numOnes, agree1, agree2);
        }
    }

    operation GeneratePlusOrMinusState (q : Qubit, sign : Int) : ()
    {
        body
        {
            if (sign == 1) {
                Set(Zero, q);
            } else {
                Set(One, q);
            }
            H(q);            
        }
    }

    operation DistinguishPlusOrMinus (q : Qubit) : Int
    {
        body
        {
            H(q);
            if (M(q) == Zero) {
                return 1;
            }
            return -1;
        }
    }

    operation DistinguishPlusOrMinusTest (count: Int, sign: Int) : (Int, Int)
    {
        body
        {
            mutable plus = 0;
            mutable minus = 0;
            using (q = Qubit[1])
            {
                for (test in 1..count)
                {
                    Set(Zero, q[0]);
                    GeneratePlusOrMinusState(q[0], sign);
                    if(DistinguishPlusOrMinus(q[0]) == 1) {
                        set plus = plus + 1;
                    } else {
                        set minus = minus + 1;
                    }
                    Set(Zero, q[0]);
                }
            }
            return (plus, minus);
        }
    }

    operation GenerateBell(qs: Qubit[], index: Int) : ()
    {
        body
        {
            if (index % 2 == 0) {
                Set(Zero, qs[0]);
            } else {
                Set(One, qs[0]);
            }
            Set(Zero, qs[1]);
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            if (index >= 2) {
                X(qs[1]);
            }
        }
    }

    operation GenerateGHZ(qs: Qubit[]) : ()
    {
        body
        {
            Set(Zero, qs[0]);
            H(qs[0]);
            for (i in 0..Length(qs)-2) {
                Set(Zero, qs[i+1]);
                CNOT(qs[i], qs[i+1]);
            }
        }
    }

    operation DistinguishBell(qs: Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            mutable index = 0;
            if (M(qs[1]) == One) {
                set index = index + 2;
            }
            H(qs[0]);
            if (M(qs[0]) == One) {
                set index = index + 1;
            }
            return index;
        }
    }

    operation DistinguishBellTest(index: Int) : Int
    {
        body
        {
            mutable ret = 0;
            using (qs = Qubit[2])
            {
                GenerateBell(qs, index);
                set ret = DistinguishBell(qs);
                Set(Zero, qs[0]);
                Set(Zero, qs[1]);
            }
            return ret;
        }
    }

    operation DistinguishMultiQubitBasis(qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        body {
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == Zero) {
                    if (bits0[i]) {
                        return 1;
                    }
                    if (bits1[i]) {
                        return 0;
                    }
                } else {
                    if (!bits0[i]) {
                        return 1;
                    }
                    if (!bits1[i]) {
                        return 0;
                    }
                }
            }
            return 0;
        }
    }

    operation DistinguishMultiQubitBasisTest() : Int {
        body {
            mutable ans = 0;
            let bits0 = [true; false];
            let bits1 = [false; true];
            using (q = Qubit[2]) {
                Set(One, q[1]);
                set ans = DistinguishMultiQubitBasis(q, bits1, bits0);
                Set(Zero, q[1]);
            }
            return ans;
        }
    }

    operation OracleKthElementTest(x0 : Result, x1 : Result, x2 : Result) : (Result, Result, Result) {
        body {
            mutable ans0 = Zero;
            mutable ans1 = Zero;
            mutable ans2 = Zero;
            using (x = Qubit[2]) {
                using (y = Qubit[1]) {
                    Set(x0, x[0]);
                    Set(x1, x[1]);
                    Set(x2, y[0]);
                    OracleParity(x, y[0]);
                    set ans0 = M(x[0]);
                    set ans1 = M(x[1]);
                    set ans2 = M(y[0]);
                    Set(Zero, x[0]);
                    Set(Zero, x[1]);
                    Set(Zero, y[0]);
                }
            }
            return (ans0, ans1, ans2);
        }
    }

    operation OracleKthElement(x : Qubit[], y : Qubit, k : Int) : () {
        body {
            CNOT(x[k], y);
        }
    }

    operation OracleParity(x : Qubit[], y : Qubit) : () {
        body {
            for (i in 0..Length(x)-1) {
                CNOT(x[i], y);
            }
        }
    }

    operation DeutschJozsa (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ans = true;
            using (x = Qubit[N]) {
                for (i in 0..Length(x)-1) {
                    H(x[i]);
                }
                using (y = Qubit[1]) {
                    X(y[0]);
                    H(y[0]);
                    Uf(x, y[0]);
                    for (i in 0..Length(x)-1) {
                        H(x[i]);
                        if (M(x[i]) == One) {
                            set ans = false;
                            X(x[i]);
                        }
                    }
                    Set(Zero, y[0]);
                }
            }
            return ans;
        }
    }

    operation DeutschJozsaTest () : Bool {
        body {
            return Solve(2, OracleParity);
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool {
        body
        {
            return DeutschJozsa(N, Uf);
        }
    }
}
