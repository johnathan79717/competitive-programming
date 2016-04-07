input = File.new(ARGV[0], "r")
output = File.new(ARGV[0]+'.out', "w")

N = input.gets.to_i
for n in 1..N
	c = input.gets.to_i
#	puts c
	i = input.gets.to_i
	p = input.gets.split.collect { |x| x.to_i }
#	puts p
	flag = false
	for i1 in 0...i
		for i2 in 0...i1
			if p[i1]+p[i2] == c
				flag = true
				break
			end
		end
		break if flag
	end
	output.puts "Case ##{n}: #{i2+1} #{i1+1}"
end
