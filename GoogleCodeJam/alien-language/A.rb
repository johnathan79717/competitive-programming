#!/usr/bin/ruby

input = File.new(ARGV[0], 'r')
output = File.new(ARGV[0]+'.out', 'w')
L,D,N = input.gets.chomp.split.map{|x| x.to_i}
dict = []
D.times	{ dict.push input.gets.chomp }

def match(word, pattern)
	L.times do |l|
		return false unless pattern[l][word[l]-97]
	end
	true
end

for n in 1..N
	pattern = []
	L.times{ pattern.push Array.new(26, false) }
	l = 0
	group = false
	input.gets.chomp.each_byte do |c|
		case c
		when '('[0] then group = true
		when ')'[0] 
			group = false
			l += 1
		else
			pattern[l][c-97] = true
			l += 1 unless group
		end
	end
	count = 0
	dict.each { |word| count += 1 if match(word, pattern) }
	output.puts "Case ##{n}: #{count}"
end

