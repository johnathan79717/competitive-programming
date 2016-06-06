time ./a.out < sample_input1 > my_output1
if diff --brief my_output1 sample_output1
echo Sample test \#1: Passed
else
echo ============================================
echo Sample Input \#1
cat sample_input1
echo ============================================
echo Sample Output \#1
cat sample_output1
echo ============================================
echo My Output \#1
cat my_output1
echo ============================================
end
time ./a.out < sample_input2 > my_output2
if diff --brief my_output2 sample_output2
echo Sample test \#2: Passed
else
echo ============================================
echo Sample Input \#2
cat sample_input2
echo ============================================
echo Sample Output \#2
cat sample_output2
echo ============================================
echo My Output \#2
cat my_output2
echo ============================================
end
time ./a.out < sample_input3 > my_output3
if diff --brief my_output3 sample_output3
echo Sample test \#3: Passed
else
echo ============================================
echo Sample Input \#3
cat sample_input3
echo ============================================
echo Sample Output \#3
cat sample_output3
echo ============================================
echo My Output \#3
cat my_output3
echo ============================================
end
