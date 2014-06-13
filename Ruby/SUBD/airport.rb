require 'csv'

class Airport
	attr_accessor :id, :gate, :f_l, :time, :flights

	def initialize
		@id = []
		@gate = []
		@f_l = []
		@time = []
		@flights = []
	end

	

	def parse_db
		@id = []
		@gate = []
		@f_l = []
		@time = []
		@flights = []
		CSV.foreach('db.csv', "r") do |row|
			@id << row[0]
			@gate << row[1]
			@f_l << row[2]
			@time << row[3]
		end
		@flights << @id << @gate << @f_l << @time
	end

	def print_db
		system('cls')
		puts "-----------------FLIGHTS-----------------"
		
		for i in 0..@flights.size - 1
			print @flights[i][0] + "/  "
		end
		puts
		
		for i in 1..@id.size - 1
			for j in 0..@flights.size - 1
				print @flights[j][i] + "/  "

			end
			puts
		end
		puts

	end

	def remove
		print "Enter the ID of the flight you wish to remove: "
		flightID = gets.chomp
		if !@id.include?(flightID)
			puts "Error. No such flight."
		else
			csv = CSV.read("db.csv")
			for i in 0..@id.size - 1
				if @id[i].to_s == flightID
					@flights.map {|a| a.delete_at(i)}
					i = 0
					
				end
			end
			CSV.open("db.csv", "w") do |csv|
				@id.size.times do
					csv << [@id[i], @gate[i], @f_l[i], @time[i]]
					i += 1
				end
			end

			puts "Flight ##{flightID} has been removed from the database."
		end
	end

	def add
		print "Enter the id of the flight: "
		id = gets.chomp

		print "Enter the gate for the plane will be arriving at/flying off: "
		gate = gets.chomp

		print "Enter 1 if the plane is flying off or 2 if its landing: "
		f_l = gets.chomp

		print "Enter the minutes the plane will take to arrive/take off: "
		time = gets.chomp
		CSV.open("db.csv", "a") do |csv|
			csv << [id, gate, f_l, time]
		end

		if f_l == 1
			puts "Flight ##{id} has been added to the database with the following status:\nThe plane will take off in #{time} minutes.\nThe passangers can board the plane at gate #{gate}"
		else 
			puts "Flight ##{id} has been added to the database with the following status:\nThe plane will land at gate #{gate} in #{time} minutes."
		end

	end

	def cmds
		puts "The available commands are:\n\nadd - Adds a new flight to the database with the entered data."
		puts
		puts "remove - Removes all the data for the entered flight."
		puts
		puts "exit - Exits the program."
	end
end



airport = Airport.new
airport.parse_db
system('cls')
airport.print_db

puts
puts "Type 'cmds' for list of commands..."

user_input = gets.chomp

while user_input != "exit"
	if user_input == "cmds"
		airport.cmds
	elsif user_input == "add"
		airport.add
		#airport.parse_db
	elsif user_input == "remove"
		airport.remove
		#airport.parse_db
	end

	if user_input.downcase == "exit"
		abort()
	else
		user_input = gets.chomp
	end
	airport.parse_db
	airport.print_db
end
