require 'io/console'

def table (rows, cols)
	@a = "_	"
	rows.times do
		(cols - 1).times do 
			print @a
		end
		print "#{@a}\n"
	end
end

y = 'y'
while y == 'y' do
	printf "Enter number of rows: "
		rows = gets.chomp
	printf "Enter number of columns: "
		columns = gets.chomp
	table( rows.to_i, columns.to_i)
	print "\n"
	printf ("Enter 'y' to go again or any other key to exit: ")
		y = gets.chomp
end