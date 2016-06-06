#!/usr/local/bin/fish
if not clang++ -g main.cc -std=c++11
    exit
end
if not ./a.out < sample_input1 > my_output1
    echo Sample test \#1: Runtime Error
else
    if diff --brief my_output1 sample_output1
        echo Sample test \#1: Accepted
    else
       echo ========================================
       echo Sample Input \#1
       cat sample_input1
       echo ========================================
       echo Sample Output \#1
       cat sample_output1
       echo ========================================
       echo My Output \#1
       cat my_output1
       echo ========================================
    end
end
if not ./a.out < sample_input2 > my_output2
    echo Sample test \#2: Runtime Error
else
    if diff --brief my_output2 sample_output2
        echo Sample test \#2: Accepted
    else
       echo ========================================
       echo Sample Input \#2
       cat sample_input2
       echo ========================================
       echo Sample Output \#2
       cat sample_output2
       echo ========================================
       echo My Output \#2
       cat my_output2
       echo ========================================
    end
end
