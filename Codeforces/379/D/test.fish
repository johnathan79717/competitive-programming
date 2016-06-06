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
if not ./a.out < sample_input3 > my_output3
    echo Sample test \#3: Runtime Error
else
    if diff --brief my_output3 sample_output3
        echo Sample test \#3: Accepted
    else
       echo ========================================
       echo Sample Input \#3
       cat sample_input3
       echo ========================================
       echo Sample Output \#3
       cat sample_output3
       echo ========================================
       echo My Output \#3
       cat my_output3
       echo ========================================
    end
end
if not ./a.out < sample_input4 > my_output4
    echo Sample test \#4: Runtime Error
else
    if diff --brief my_output4 sample_output4
        echo Sample test \#4: Accepted
    else
       echo ========================================
       echo Sample Input \#4
       cat sample_input4
       echo ========================================
       echo Sample Output \#4
       cat sample_output4
       echo ========================================
       echo My Output \#4
       cat my_output4
       echo ========================================
    end
end
if not ./a.out < sample_input5 > my_output5
    echo Sample test \#5: Runtime Error
else
    if diff --brief my_output5 sample_output5
        echo Sample test \#5: Accepted
    else
       echo ========================================
       echo Sample Input \#5
       cat sample_input5
       echo ========================================
       echo Sample Output \#5
       cat sample_output5
       echo ========================================
       echo My Output \#5
       cat my_output5
       echo ========================================
    end
end
