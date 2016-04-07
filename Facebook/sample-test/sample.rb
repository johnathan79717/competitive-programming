N, K = gets.chomp.split.map{|x| x.to_i}

initial = gets.chomp.split.map{|x| x.to_i}
final = gets.chomp.split.map{|x| x.to_i}
pegs = Array.new(K, [])

initial.each_with_index do |x, i|
	puts "x:#{x} i:#{i}"
	pegs[x-1].unshift(i+1)
	puts pegs
end

