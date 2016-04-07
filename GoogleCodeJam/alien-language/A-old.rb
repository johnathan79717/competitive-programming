#!/usr/bin/ruby

input = File.new(ARGV[0], 'r')
output = File.new(ARGV[0]+'.out', 'w')

L,D,N = input.gets.chomp.split.map{|x| x.to_i}
dict = {}
D.times	{ dict[input.gets.chomp] = 0 }
for n in 1..N
	dict.each_key {|x| dict[x] = 0}
	patt = input.gets.chomp
	l = 0
	group = false
	patt.each_byte do |c|
		case c
		when '('[0] then group = true
		when ')'[0] 
			group = false
			l += 1
		else
			dict.each_key { |word| dict[word] += 1 if word[l] == c }
			l += 1 unless group
		end
	end
	count = 0
	dict.each_value { |x| count += 1 if x == L }
	output.puts "Case ##{n}: #{count}"
end
