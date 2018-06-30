using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.Simulation.Simulators;

namespace Solution
{
    class Driver
    {
        static void Main(string[] args)
        {
            using (var sim = new QuantumSimulator())
            {
                // for (int index = 0; index < 4; index++) {
                // Result[] initials = new Result[] { Result.Zero, Result.One };
                // foreach (Result x0 in initials) {
                //     foreach (Result x1 in initials) {
                //         foreach (Result x2 in initials) {
                            // for (int k = 0; k < 2; k++) {
                                var res = DeutschJozsaTest.Run(sim).Result;
                                // System.Console.WriteLine((x0, x1, x2));
                                System.Console.WriteLine(res);
                            // }
                //         }
                //     }
                // }
            }
        }
    }
}