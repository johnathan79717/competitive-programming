#pragma warning disable 1591
using System;
using Microsoft.Quantum.Primitive;
using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.MetaData.Attributes;

[assembly: OperationDeclaration("Solution", "Set (desired : Result, q1 : Qubit) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 156L, 7L, 5L)]
[assembly: OperationDeclaration("Solution", "Test (count : Int, initial0 : Result, initial1 : Result, initial2 : Result) : (Int, Int, Int, Int)", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 428L, 18L, 5L)]
[assembly: OperationDeclaration("Solution", "GeneratePlusOrMinusState (q : Qubit, sign : Int) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 1782L, 62L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishPlusOrMinus (q : Qubit) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 2049L, 75L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishPlusOrMinusTest (count : Int, sign : Int) : (Int, Int)", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 2298L, 87L, 5L)]
[assembly: OperationDeclaration("Solution", "GenerateBell (qs : Qubit[], index : Int) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 2991L, 111L, 5L)]
[assembly: OperationDeclaration("Solution", "GenerateGHZ (qs : Qubit[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 3389L, 129L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishBell (qs : Qubit[]) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 3678L, 142L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishBellTest (index : Int) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 4080L, 159L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishMultiQubitBasis (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 4501L, 174L, 94L)]
[assembly: OperationDeclaration("Solution", "DistinguishMultiQubitBasisTest () : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 5141L, 197L, 54L)]
[assembly: OperationDeclaration("Solution", "OracleKthElementTest (x0 : Result, x1 : Result, x2 : Result) : (Result, Result, Result)", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 5606L, 211L, 102L)]
[assembly: OperationDeclaration("Solution", "OracleKthElement (x : Qubit[], y : Qubit, k : Int) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 6355L, 234L, 70L)]
[assembly: OperationDeclaration("Solution", "OracleParity (x : Qubit[], y : Qubit) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 6478L, 240L, 57L)]
[assembly: OperationDeclaration("Solution", "DeutschJozsa (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 6685L, 249L, 5L)]
[assembly: OperationDeclaration("Solution", "Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 7463L, 275L, 5L)]
[assembly: OperationDeclaration("Solution", "DeutschJozsaTest () : Bool", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 8193L, 301L, 42L)]
[assembly: OperationDeclaration("Solution", "GenerateSuperpositionOfAllStates (qs : Qubit[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 8350L, 307L, 68L)]
[assembly: OperationDeclaration("Solution", "DetermineZeroAndW (qs : Qubit[]) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 8526L, 315L, 54L)]
[assembly: OperationDeclaration("Solution", "GenerateSuperpositionOfZeroAndABasis (qs : Qubit[], bits : Bool[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 8823L, 326L, 87L)]
[assembly: OperationDeclaration("Solution", "DistinguishGHZAndW (qs : Qubit[]) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 9345L, 344L, 5L)]
[assembly: OperationDeclaration("Solution", "GenerateSuperpositionOfTwoBases (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 9675L, 357L, 5L)]
[assembly: OperationDeclaration("Solution", "OracleXor (x : Qubit[], y : Qubit, b : Int[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 10416L, 382L, 5L)]
[assembly: OperationDeclaration("Solution", "OracleDot (x : Qubit[], y : Qubit, b : Int[]) : ()", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 10801L, 398L, 5L)]
[assembly: OperationDeclaration("Solution", "DistinguishFourStates1 (qs : Qubit[]) : Int", new string[] { }, "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs", 11090L, 411L, 5L)]
#line hidden
namespace Solution
{
    public class Set : Operation<(Result,Qubit), QVoid>, ICallable
    {
        public Set(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Result,Qubit)>, IApplyData
        {
            public In((Result,Qubit) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits
            {
                get
                {
                    yield return Data.Item2;
                }
            }
        }

        String ICallable.Name => "Set";
        String ICallable.FullName => "Solution.Set";
        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(Result,Qubit), QVoid> Body => (__in) =>
        {
            var (desired,q1) = __in;
#line 10 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var current = M.Apply(q1);
#line 11 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((desired != current))
            {
#line 12 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveX.Apply(q1);
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((Result,Qubit) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, Result desired, Qubit q1)
        {
            return __m__.Run<Set, (Result,Qubit), QVoid>((desired, q1));
        }
    }

    public class Test : Operation<(Int64,Result,Result,Result), (Int64,Int64,Int64,Int64)>, ICallable
    {
        public Test(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Int64,Result,Result,Result)>, IApplyData
        {
            public In((Int64,Result,Result,Result) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        public class Out : QTuple<(Int64,Int64,Int64,Int64)>, IApplyData
        {
            public Out((Int64,Int64,Int64,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        String ICallable.Name => "Test";
        String ICallable.FullName => "Solution.Test";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected ICallable<QArray<Qubit>, QVoid> GenerateGHZ
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<(Int64,Result,Result,Result), (Int64,Int64,Int64,Int64)> Body => (__in) =>
        {
            var (count,initial0,initial1,initial2) = __in;
#line 21 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var numOnes = 0L;
#line 22 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var agree1 = 0L;
#line 23 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var agree2 = 0L;
#line 24 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var qubits = Allocate.Apply(3L);
#line 26 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var test in new Range(1L, count))
            {
#line 28 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((initial0, qubits[0L]));
#line 29 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((initial1, qubits[1L]));
#line 30 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((initial2, qubits[2L]));
#line 32 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                GenerateGHZ.Apply(qubits);
#line 33 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                var res = M.Apply(qubits[0L]);
#line 35 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((res == M.Apply(qubits[1L])))
                {
#line 37 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    agree1 = (agree1 + 1L);
                }

#line 40 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((res == M.Apply(qubits[2L])))
                {
#line 42 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    agree2 = (agree2 + 1L);
                }

                // Count the number of ones we saw:
#line 46 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((res == Result.One))
                {
#line 48 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    numOnes = (numOnes + 1L);
                }
            }

#line 52 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qubits[0L]));
#line 53 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qubits[1L]));
#line 54 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qubits[2L]));
#line hidden
            Release.Apply(qubits);
            // Return number of times we saw a |0> and number of times we saw a |1>
#line 57 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return ((count - numOnes), numOnes, agree1, agree2);
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.GenerateGHZ = this.Factory.Get<ICallable<QArray<Qubit>, QVoid>>(typeof(Solution.GenerateGHZ));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn((Int64,Result,Result,Result) data) => new In(data);
        public override IApplyData __dataOut((Int64,Int64,Int64,Int64) data) => new Out(data);
        public static System.Threading.Tasks.Task<(Int64,Int64,Int64,Int64)> Run(IOperationFactory __m__, Int64 count, Result initial0, Result initial1, Result initial2)
        {
            return __m__.Run<Test, (Int64,Result,Result,Result), (Int64,Int64,Int64,Int64)>((count, initial0, initial1, initial2));
        }
    }

    public class GeneratePlusOrMinusState : Operation<(Qubit,Int64), QVoid>, ICallable
    {
        public GeneratePlusOrMinusState(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Qubit,Int64)>, IApplyData
        {
            public In((Qubit,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits
            {
                get
                {
                    yield return Data.Item1;
                }
            }
        }

        String ICallable.Name => "GeneratePlusOrMinusState";
        String ICallable.FullName => "Solution.GeneratePlusOrMinusState";
        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<(Qubit,Int64), QVoid> Body => (__in) =>
        {
            var (q,sign) = __in;
#line 65 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((sign == 1L))
            {
#line 66 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.Zero, q));
            }
            else
            {
#line 68 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.One, q));
            }

#line 70 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(q);
#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn((Qubit,Int64) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, Qubit q, Int64 sign)
        {
            return __m__.Run<GeneratePlusOrMinusState, (Qubit,Int64), QVoid>((q, sign));
        }
    }

    public class DistinguishPlusOrMinus : Operation<Qubit, Int64>, ICallable
    {
        public DistinguishPlusOrMinus(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishPlusOrMinus";
        String ICallable.FullName => "Solution.DistinguishPlusOrMinus";
        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<Qubit, Int64> Body => (__in) =>
        {
            var q = __in;
#line 78 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(q);
#line 79 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((M.Apply(q) == Result.Zero))
            {
#line 80 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                return 1L;
            }

#line 82 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return -(1L);
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn(Qubit data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, Qubit q)
        {
            return __m__.Run<DistinguishPlusOrMinus, Qubit, Int64>(q);
        }
    }

    public class DistinguishPlusOrMinusTest : Operation<(Int64,Int64), (Int64,Int64)>, ICallable
    {
        public DistinguishPlusOrMinusTest(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Int64,Int64)>, IApplyData
        {
            public In((Int64,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        public class Out : QTuple<(Int64,Int64)>, IApplyData
        {
            public Out((Int64,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        String ICallable.Name => "DistinguishPlusOrMinusTest";
        String ICallable.FullName => "Solution.DistinguishPlusOrMinusTest";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected ICallable<Qubit, Int64> DistinguishPlusOrMinus
        {
            get;
            set;
        }

        protected ICallable<(Qubit,Int64), QVoid> GeneratePlusOrMinusState
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<(Int64,Int64), (Int64,Int64)> Body => (__in) =>
        {
            var (count,sign) = __in;
#line 90 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var plus = 0L;
#line 91 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var minus = 0L;
#line 92 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var q = Allocate.Apply(1L);
#line 94 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var test in new Range(1L, count))
            {
#line 96 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.Zero, q[0L]));
#line 97 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                GeneratePlusOrMinusState.Apply((q[0L], sign));
#line 98 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((DistinguishPlusOrMinus.Apply(q[0L]) == 1L))
                {
#line 99 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    plus = (plus + 1L);
                }
                else
                {
#line 101 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    minus = (minus + 1L);
                }

#line 103 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.Zero, q[0L]));
            }

#line hidden
            Release.Apply(q);
#line 106 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return (plus, minus);
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.DistinguishPlusOrMinus = this.Factory.Get<ICallable<Qubit, Int64>>(typeof(Solution.DistinguishPlusOrMinus));
            this.GeneratePlusOrMinusState = this.Factory.Get<ICallable<(Qubit,Int64), QVoid>>(typeof(Solution.GeneratePlusOrMinusState));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn((Int64,Int64) data) => new In(data);
        public override IApplyData __dataOut((Int64,Int64) data) => new Out(data);
        public static System.Threading.Tasks.Task<(Int64,Int64)> Run(IOperationFactory __m__, Int64 count, Int64 sign)
        {
            return __m__.Run<DistinguishPlusOrMinusTest, (Int64,Int64), (Int64,Int64)>((count, sign));
        }
    }

    public class GenerateBell : Operation<(QArray<Qubit>,Int64), QVoid>, ICallable
    {
        public GenerateBell(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,Int64)>, IApplyData
        {
            public In((QArray<Qubit>,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item1)?.Qubits;
        }

        String ICallable.Name => "GenerateBell";
        String ICallable.FullName => "Solution.GenerateBell";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,Int64), QVoid> Body => (__in) =>
        {
            var (qs,index) = __in;
#line 114 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if (((index % 2L) == 0L))
            {
#line 115 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.Zero, qs[0L]));
            }
            else
            {
#line 117 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.One, qs[0L]));
            }

#line 119 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qs[1L]));
#line 120 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(qs[0L]);
#line 121 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveCNOT.Apply((qs[0L], qs[1L]));
#line 122 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((index >= 2L))
            {
#line 123 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveX.Apply(qs[1L]);
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((QArray<Qubit>,Int64) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs, Int64 index)
        {
            return __m__.Run<GenerateBell, (QArray<Qubit>,Int64), QVoid>((qs, index));
        }
    }

    public class GenerateGHZ : Operation<QArray<Qubit>, QVoid>, ICallable
    {
        public GenerateGHZ(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "GenerateGHZ";
        String ICallable.FullName => "Solution.GenerateGHZ";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, QVoid> Body => (__in) =>
        {
            var qs = __in;
#line 132 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qs[0L]));
#line 133 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(qs[0L]);
#line 134 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 2L)))
            {
#line 135 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                Set.Apply((Result.Zero, qs[(i + 1L)]));
#line 136 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveCNOT.Apply((qs[i], qs[(i + 1L)]));
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<GenerateGHZ, QArray<Qubit>, QVoid>(qs);
        }
    }

    public class DistinguishBell : Operation<QArray<Qubit>, Int64>, ICallable
    {
        public DistinguishBell(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishBell";
        String ICallable.FullName => "Solution.DistinguishBell";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, Int64> Body => (__in) =>
        {
            var qs = __in;
#line 145 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveCNOT.Apply((qs[0L], qs[1L]));
#line 146 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var index = 0L;
#line 147 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((M.Apply(qs[1L]) == Result.One))
            {
#line 148 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                index = (index + 2L);
            }

#line 150 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(qs[0L]);
#line 151 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            if ((M.Apply(qs[0L]) == Result.One))
            {
#line 152 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                index = (index + 1L);
            }

#line 154 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return index;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<DistinguishBell, QArray<Qubit>, Int64>(qs);
        }
    }

    public class DistinguishBellTest : Operation<Int64, Int64>, ICallable
    {
        public DistinguishBellTest(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishBellTest";
        String ICallable.FullName => "Solution.DistinguishBellTest";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected ICallable<QArray<Qubit>, Int64> DistinguishBell
        {
            get;
            set;
        }

        protected ICallable<(QArray<Qubit>,Int64), QVoid> GenerateBell
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<Int64, Int64> Body => (__in) =>
        {
            var index = __in;
#line 162 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ret = 0L;
#line 163 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var qs = Allocate.Apply(2L);
#line 165 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            GenerateBell.Apply((qs, index));
#line 166 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            ret = DistinguishBell.Apply(qs);
#line 167 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qs[0L]));
#line 168 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, qs[1L]));
#line hidden
            Release.Apply(qs);
#line 170 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return ret;
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.DistinguishBell = this.Factory.Get<ICallable<QArray<Qubit>, Int64>>(typeof(Solution.DistinguishBell));
            this.GenerateBell = this.Factory.Get<ICallable<(QArray<Qubit>,Int64), QVoid>>(typeof(Solution.GenerateBell));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn(Int64 data) => new QTuple<Int64>(data);
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, Int64 index)
        {
            return __m__.Run<DistinguishBellTest, Int64, Int64>(index);
        }
    }

    public class DistinguishMultiQubitBasis : Operation<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), Int64>, ICallable
    {
        public DistinguishMultiQubitBasis(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>)>, IApplyData
        {
            public In((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item1)?.Qubits;
        }

        String ICallable.Name => "DistinguishMultiQubitBasis";
        String ICallable.FullName => "Solution.DistinguishMultiQubitBasis";
        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), Int64> Body => (__in) =>
        {
            var (qs,bits0,bits1) = __in;
#line 176 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 177 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((M.Apply(qs[i]) == Result.Zero))
                {
#line 178 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    if (bits0[i])
                    {
#line 179 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        return 1L;
                    }

#line 181 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    if (bits1[i])
                    {
#line 182 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        return 0L;
                    }
                }
                else
                {
#line 185 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    if (!(bits0[i]))
                    {
#line 186 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        return 1L;
                    }

#line 188 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    if (!(bits1[i]))
                    {
#line 189 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        return 0L;
                    }
                }
            }

#line 193 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return 0L;
        }

        ;
        public override void Init()
        {
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) => new In(data);
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs, QArray<Boolean> bits0, QArray<Boolean> bits1)
        {
            return __m__.Run<DistinguishMultiQubitBasis, (QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), Int64>((qs, bits0, bits1));
        }
    }

    public class DistinguishMultiQubitBasisTest : Operation<QVoid, Int64>, ICallable
    {
        public DistinguishMultiQubitBasisTest(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishMultiQubitBasisTest";
        String ICallable.FullName => "Solution.DistinguishMultiQubitBasisTest";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected ICallable<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), Int64> DistinguishMultiQubitBasis
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<QVoid, Int64> Body => (__in) =>
        {
#line 199 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ans = 0L;
#line 200 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var bits0 = new QArray<Boolean>(true, false);
#line 201 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var bits1 = new QArray<Boolean>(false, true);
#line 202 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var q = Allocate.Apply(2L);
#line 203 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.One, q[1L]));
#line 204 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            ans = DistinguishMultiQubitBasis.Apply((q, bits1, bits0));
#line 205 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, q[1L]));
#line hidden
            Release.Apply(q);
#line 207 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return ans;
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.DistinguishMultiQubitBasis = this.Factory.Get<ICallable<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), Int64>>(typeof(Solution.DistinguishMultiQubitBasis));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn(QVoid data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__)
        {
            return __m__.Run<DistinguishMultiQubitBasisTest, QVoid, Int64>(QVoid.Instance);
        }
    }

    public class OracleKthElementTest : Operation<(Result,Result,Result), (Result,Result,Result)>, ICallable
    {
        public OracleKthElementTest(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Result,Result,Result)>, IApplyData
        {
            public In((Result,Result,Result) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        public class Out : QTuple<(Result,Result,Result)>, IApplyData
        {
            public Out((Result,Result,Result) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => null;
        }

        String ICallable.Name => "OracleKthElementTest";
        String ICallable.FullName => "Solution.OracleKthElementTest";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected ICallable<(QArray<Qubit>,Qubit), QVoid> OracleParity
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        public override Func<(Result,Result,Result), (Result,Result,Result)> Body => (__in) =>
        {
            var (x0,x1,x2) = __in;
#line 213 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ans0 = Result.Zero;
#line 214 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ans1 = Result.Zero;
#line 215 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ans2 = Result.Zero;
#line 216 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var x = Allocate.Apply(2L);
#line 217 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var y = Allocate.Apply(1L);
#line 218 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((x0, x[0L]));
#line 219 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((x1, x[1L]));
#line 220 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((x2, y[0L]));
#line 221 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            OracleParity.Apply((x, y[0L]));
#line 222 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            ans0 = M.Apply(x[0L]);
#line 223 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            ans1 = M.Apply(x[1L]);
#line 224 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            ans2 = M.Apply(y[0L]);
#line 225 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, x[0L]));
#line 226 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, x[1L]));
#line 227 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, y[0L]));
#line hidden
            Release.Apply(y);
#line hidden
            Release.Apply(x);
#line 230 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return (ans0, ans1, ans2);
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.OracleParity = this.Factory.Get<ICallable<(QArray<Qubit>,Qubit), QVoid>>(typeof(Solution.OracleParity));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
        }

        public override IApplyData __dataIn((Result,Result,Result) data) => new In(data);
        public override IApplyData __dataOut((Result,Result,Result) data) => new Out(data);
        public static System.Threading.Tasks.Task<(Result,Result,Result)> Run(IOperationFactory __m__, Result x0, Result x1, Result x2)
        {
            return __m__.Run<OracleKthElementTest, (Result,Result,Result), (Result,Result,Result)>((x0, x1, x2));
        }
    }

    public class OracleKthElement : Operation<(QArray<Qubit>,Qubit,Int64), QVoid>, ICallable
    {
        public OracleKthElement(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,Qubit,Int64)>, IApplyData
        {
            public In((QArray<Qubit>,Qubit,Int64) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => Qubit.Concat(((IApplyData)Data.Item1)?.Qubits, ((IApplyData)Data.Item2)?.Qubits);
        }

        String ICallable.Name => "OracleKthElement";
        String ICallable.FullName => "Solution.OracleKthElement";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,Qubit,Int64), QVoid> Body => (__in) =>
        {
            var (x,y,k) = __in;
#line 236 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveCNOT.Apply((x[k], y));
#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
        }

        public override IApplyData __dataIn((QArray<Qubit>,Qubit,Int64) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> x, Qubit y, Int64 k)
        {
            return __m__.Run<OracleKthElement, (QArray<Qubit>,Qubit,Int64), QVoid>((x, y, k));
        }
    }

    public class OracleParity : Operation<(QArray<Qubit>,Qubit), QVoid>, ICallable
    {
        public OracleParity(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,Qubit)>, IApplyData
        {
            public In((QArray<Qubit>,Qubit) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => Qubit.Concat(((IApplyData)Data.Item1)?.Qubits, ((IApplyData)Data.Item2)?.Qubits);
        }

        String ICallable.Name => "OracleParity";
        String ICallable.FullName => "Solution.OracleParity";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,Qubit), QVoid> Body => (__in) =>
        {
            var (x,y) = __in;
#line 242 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (x.Count - 1L)))
            {
#line 243 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveCNOT.Apply((x[i], y));
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
        }

        public override IApplyData __dataIn((QArray<Qubit>,Qubit) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> x, Qubit y)
        {
            return __m__.Run<OracleParity, (QArray<Qubit>,Qubit), QVoid>((x, y));
        }
    }

    public class DeutschJozsa : Operation<(Int64,ICallable), Boolean>, ICallable
    {
        public DeutschJozsa(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Int64,ICallable)>, IApplyData
        {
            public In((Int64,ICallable) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item2)?.Qubits;
        }

        String ICallable.Name => "DeutschJozsa";
        String ICallable.FullName => "Solution.DeutschJozsa";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(Int64,ICallable), Boolean> Body => (__in) =>
        {
            var (N,Uf) = __in;
#line 252 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var ans = true;
#line 253 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var x = Allocate.Apply(N);
#line 254 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (x.Count - 1L)))
            {
#line 255 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveH.Apply(x[i]);
            }

#line 257 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var y = Allocate.Apply(1L);
#line 258 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveX.Apply(y[0L]);
#line 259 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(y[0L]);
#line 260 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Uf.Apply((x, y[0L]));
#line 261 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (x.Count - 1L)))
            {
#line 262 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveH.Apply(x[i]);
#line 263 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((M.Apply(x[i]) == Result.One))
                {
#line 264 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    ans = false;
#line 265 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveX.Apply(x[i]);
                }
            }

#line 268 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, y[0L]));
#line hidden
            Release.Apply(y);
#line hidden
            Release.Apply(x);
#line 271 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return ans;
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((Int64,ICallable) data) => new In(data);
        public override IApplyData __dataOut(Boolean data) => new QTuple<Boolean>(data);
        public static System.Threading.Tasks.Task<Boolean> Run(IOperationFactory __m__, Int64 N, ICallable Uf)
        {
            return __m__.Run<DeutschJozsa, (Int64,ICallable), Boolean>((N, Uf));
        }
    }

    public class Solve : Operation<(Int64,ICallable), QArray<Int64>>, ICallable
    {
        public Solve(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(Int64,ICallable)>, IApplyData
        {
            public In((Int64,ICallable) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item2)?.Qubits;
        }

        String ICallable.Name => "Solve";
        String ICallable.FullName => "Solution.Solve";
        protected Allocate Allocate
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected Release Release
        {
            get;
            set;
        }

        protected ICallable<(Result,Qubit), QVoid> Set
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(Int64,ICallable), QArray<Int64>> Body => (__in) =>
        {
            var (N,Uf) = __in;
#line 278 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var b = new QArray<Int64>(N);
#line 279 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var x = Allocate.Apply(N);
#line 280 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (N - 1L)))
            {
#line 281 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveH.Apply(x[i]);
            }

#line 283 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var y = Allocate.Apply(1L);
#line 284 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveX.Apply(y[0L]);
#line 285 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(y[0L]);
#line 286 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Uf.Apply((x, y[0L]));
#line 287 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (N - 1L)))
            {
#line 288 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveH.Apply(x[i]);
#line 289 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((M.Apply(x[i]) == Result.One))
                {
#line 290 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    b[i] = 1L;
#line 291 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveX.Apply(x[i]);
                }
            }

#line 294 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            Set.Apply((Result.Zero, y[0L]));
#line hidden
            Release.Apply(y);
#line hidden
            Release.Apply(x);
#line 297 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return b;
        }

        ;
        public override void Init()
        {
            this.Allocate = this.Factory.Get<Allocate>(typeof(Microsoft.Quantum.Primitive.Allocate));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.Release = this.Factory.Get<Release>(typeof(Microsoft.Quantum.Primitive.Release));
            this.Set = this.Factory.Get<ICallable<(Result,Qubit), QVoid>>(typeof(Solution.Set));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((Int64,ICallable) data) => new In(data);
        public override IApplyData __dataOut(QArray<Int64> data) => data;
        public static System.Threading.Tasks.Task<QArray<Int64>> Run(IOperationFactory __m__, Int64 N, ICallable Uf)
        {
            return __m__.Run<Solve, (Int64,ICallable), QArray<Int64>>((N, Uf));
        }
    }

    public class DeutschJozsaTest : Operation<QVoid, Boolean>, ICallable
    {
        public DeutschJozsaTest(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DeutschJozsaTest";
        String ICallable.FullName => "Solution.DeutschJozsaTest";
        protected ICallable<(Int64,ICallable), Boolean> DeutschJozsa
        {
            get;
            set;
        }

        protected ICallable<(QArray<Qubit>,Qubit), QVoid> OracleParity
        {
            get;
            set;
        }

        public override Func<QVoid, Boolean> Body => (__in) =>
        {
#line 303 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return DeutschJozsa.Apply((2L, ((ICallable)OracleParity)));
        }

        ;
        public override void Init()
        {
            this.DeutschJozsa = this.Factory.Get<ICallable<(Int64,ICallable), Boolean>>(typeof(Solution.DeutschJozsa));
            this.OracleParity = this.Factory.Get<ICallable<(QArray<Qubit>,Qubit), QVoid>>(typeof(Solution.OracleParity));
        }

        public override IApplyData __dataIn(QVoid data) => data;
        public override IApplyData __dataOut(Boolean data) => new QTuple<Boolean>(data);
        public static System.Threading.Tasks.Task<Boolean> Run(IOperationFactory __m__)
        {
            return __m__.Run<DeutschJozsaTest, QVoid, Boolean>(QVoid.Instance);
        }
    }

    public class GenerateSuperpositionOfAllStates : Operation<QArray<Qubit>, QVoid>, ICallable
    {
        public GenerateSuperpositionOfAllStates(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "GenerateSuperpositionOfAllStates";
        String ICallable.FullName => "Solution.GenerateSuperpositionOfAllStates";
        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, QVoid> Body => (__in) =>
        {
            var qs = __in;
#line 309 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 310 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                MicrosoftQuantumPrimitiveH.Apply(qs[i]);
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<GenerateSuperpositionOfAllStates, QArray<Qubit>, QVoid>(qs);
        }
    }

    public class DetermineZeroAndW : Operation<QArray<Qubit>, Int64>, ICallable
    {
        public DetermineZeroAndW(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DetermineZeroAndW";
        String ICallable.FullName => "Solution.DetermineZeroAndW";
        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, Int64> Body => (__in) =>
        {
            var qs = __in;
#line 317 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 318 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((M.Apply(qs[i]) == Result.One))
                {
#line 319 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    return 1L;
                }
            }

#line 322 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return 0L;
        }

        ;
        public override void Init()
        {
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<DetermineZeroAndW, QArray<Qubit>, Int64>(qs);
        }
    }

    public class GenerateSuperpositionOfZeroAndABasis : Operation<(QArray<Qubit>,QArray<Boolean>), QVoid>, ICallable
    {
        public GenerateSuperpositionOfZeroAndABasis(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,QArray<Boolean>)>, IApplyData
        {
            public In((QArray<Qubit>,QArray<Boolean>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item1)?.Qubits;
        }

        String ICallable.Name => "GenerateSuperpositionOfZeroAndABasis";
        String ICallable.FullName => "Solution.GenerateSuperpositionOfZeroAndABasis";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,QArray<Boolean>), QVoid> Body => (__in) =>
        {
            var (qs,bits) = __in;
#line 328 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var done = false;
#line 329 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 330 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((!(done) && bits[i]))
                {
#line 331 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    done = true;
#line 332 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveH.Apply(qs[i]);
#line 333 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    foreach (var j in new Range(0L, (qs.Count - 1L)))
                    {
#line 334 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        if (((j != i) && bits[j]))
                        {
#line 335 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                            MicrosoftQuantumPrimitiveCNOT.Apply((qs[i], qs[j]));
                        }
                    }
                }
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
        }

        public override IApplyData __dataIn((QArray<Qubit>,QArray<Boolean>) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs, QArray<Boolean> bits)
        {
            return __m__.Run<GenerateSuperpositionOfZeroAndABasis, (QArray<Qubit>,QArray<Boolean>), QVoid>((qs, bits));
        }
    }

    public class DistinguishGHZAndW : Operation<QArray<Qubit>, Int64>, ICallable
    {
        public DistinguishGHZAndW(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishGHZAndW";
        String ICallable.FullName => "Solution.DistinguishGHZAndW";
        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, Int64> Body => (__in) =>
        {
            var qs = __in;
#line 347 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 2L)))
            {
#line 348 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((M.Apply(qs[i]) != M.Apply(qs[(i + 1L)])))
                {
#line 349 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    return 1L;
                }
            }

#line 352 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return 0L;
        }

        ;
        public override void Init()
        {
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<DistinguishGHZAndW, QArray<Qubit>, Int64>(qs);
        }
    }

    public class GenerateSuperpositionOfTwoBases : Operation<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid>, ICallable
    {
        public GenerateSuperpositionOfTwoBases(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>)>, IApplyData
        {
            public In((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => ((IApplyData)Data.Item1)?.Qubits;
        }

        String ICallable.Name => "GenerateSuperpositionOfTwoBases";
        String ICallable.FullName => "Solution.GenerateSuperpositionOfTwoBases";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid> Body => (__in) =>
        {
            var (qs,bits0,bits1) = __in;
            // your code here
#line 361 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            var done = false;
#line 362 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 363 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((!(done) && (bits0[i] != bits1[i])))
                {
#line 364 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    done = true;
#line 365 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveH.Apply(qs[i]);
#line 366 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    foreach (var j in new Range(0L, (qs.Count - 1L)))
                    {
#line 367 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                        if (((j != i) && (bits0[j] != bits1[j])))
                        {
#line 368 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                            MicrosoftQuantumPrimitiveCNOT.Apply((qs[i], qs[j]));
                        }
                    }
                }
            }

#line 373 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 374 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if (bits0[i])
                {
#line 375 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveX.Apply(qs[i]);
                }
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((QArray<Qubit>,QArray<Boolean>,QArray<Boolean>) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> qs, QArray<Boolean> bits0, QArray<Boolean> bits1)
        {
            return __m__.Run<GenerateSuperpositionOfTwoBases, (QArray<Qubit>,QArray<Boolean>,QArray<Boolean>), QVoid>((qs, bits0, bits1));
        }
    }

    public class OracleXor : Operation<(QArray<Qubit>,Qubit,QArray<Int64>), QVoid>, ICallable
    {
        public OracleXor(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,Qubit,QArray<Int64>)>, IApplyData
        {
            public In((QArray<Qubit>,Qubit,QArray<Int64>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => Qubit.Concat(((IApplyData)Data.Item1)?.Qubits, ((IApplyData)Data.Item2)?.Qubits);
        }

        String ICallable.Name => "OracleXor";
        String ICallable.FullName => "Solution.OracleXor";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveX
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,Qubit,QArray<Int64>), QVoid> Body => (__in) =>
        {
            var (x,y,b) = __in;
            // your code here
#line 386 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (x.Count - 1L)))
            {
#line 387 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((b[i] == 1L))
                {
#line 388 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveCNOT.Apply((x[i], y));
                }
                else
                {
#line 390 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveCNOT.Apply((x[i], y));
#line 391 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveX.Apply(y);
                }
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
            this.MicrosoftQuantumPrimitiveX = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.X));
        }

        public override IApplyData __dataIn((QArray<Qubit>,Qubit,QArray<Int64>) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> x, Qubit y, QArray<Int64> b)
        {
            return __m__.Run<OracleXor, (QArray<Qubit>,Qubit,QArray<Int64>), QVoid>((x, y, b));
        }
    }

    public class OracleDot : Operation<(QArray<Qubit>,Qubit,QArray<Int64>), QVoid>, ICallable
    {
        public OracleDot(IOperationFactory m) : base(m)
        {
        }

        public class In : QTuple<(QArray<Qubit>,Qubit,QArray<Int64>)>, IApplyData
        {
            public In((QArray<Qubit>,Qubit,QArray<Int64>) data) : base(data)
            {
            }

            System.Collections.Generic.IEnumerable<Qubit> IApplyData.Qubits => Qubit.Concat(((IApplyData)Data.Item1)?.Qubits, ((IApplyData)Data.Item2)?.Qubits);
        }

        String ICallable.Name => "OracleDot";
        String ICallable.FullName => "Solution.OracleDot";
        protected IUnitary<(Qubit,Qubit)> MicrosoftQuantumPrimitiveCNOT
        {
            get;
            set;
        }

        public override Func<(QArray<Qubit>,Qubit,QArray<Int64>), QVoid> Body => (__in) =>
        {
            var (x,y,b) = __in;
            // your code here
#line 402 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            foreach (var i in new Range(0L, (x.Count - 1L)))
            {
#line 403 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                if ((b[i] == 1L))
                {
#line 404 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
                    MicrosoftQuantumPrimitiveCNOT.Apply((x[i], y));
                }
            }

#line hidden
            return QVoid.Instance;
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveCNOT = this.Factory.Get<IUnitary<(Qubit,Qubit)>>(typeof(Microsoft.Quantum.Primitive.CNOT));
        }

        public override IApplyData __dataIn((QArray<Qubit>,Qubit,QArray<Int64>) data) => new In(data);
        public override IApplyData __dataOut(QVoid data) => data;
        public static System.Threading.Tasks.Task<QVoid> Run(IOperationFactory __m__, QArray<Qubit> x, Qubit y, QArray<Int64> b)
        {
            return __m__.Run<OracleDot, (QArray<Qubit>,Qubit,QArray<Int64>), QVoid>((x, y, b));
        }
    }

    public class DistinguishFourStates1 : Operation<QArray<Qubit>, Int64>, ICallable
    {
        public DistinguishFourStates1(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "DistinguishFourStates1";
        String ICallable.FullName => "Solution.DistinguishFourStates1";
        protected IUnitary<Qubit> MicrosoftQuantumPrimitiveH
        {
            get;
            set;
        }

        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        protected ICallable<QArray<Result>, Int64> MicrosoftQuantumCanonResultAsInt
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, Int64> Body => (__in) =>
        {
            var qs = __in;
#line 414 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(qs[0L]);
#line 415 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            MicrosoftQuantumPrimitiveH.Apply(qs[1L]);
#line 416 "/Users/jhao/Workspace/competitive-programming/Q#/Solution/Operation.qs"
            return MicrosoftQuantumCanonResultAsInt.Apply(new QArray<Result>(M.Apply(qs[1L]), M.Apply(qs[0L])));
        }

        ;
        public override void Init()
        {
            this.MicrosoftQuantumPrimitiveH = this.Factory.Get<IUnitary<Qubit>>(typeof(Microsoft.Quantum.Primitive.H));
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
            this.MicrosoftQuantumCanonResultAsInt = this.Factory.Get<ICallable<QArray<Result>, Int64>>(typeof(Microsoft.Quantum.Canon.ResultAsInt));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<DistinguishFourStates1, QArray<Qubit>, Int64>(qs);
        }
    }
}