require "csv"

	names = Hash.new("")
	
	CSV.foreach(File.join(ARGV[0],"Evaluation 2013-2014 - Sheet2.csv")) do |row|

		if row[0].to_s.length != 1
			next
		end

		name = row[1].to_s.strip + " " + row[2].to_s.strip

		if row[3].to_s != 0 
			names[row[3]] = [name,0,0]
		else
			row[3] = name
			names[row[3]] = [name,0,0]
		end

	end

	CSV.foreach(File.join(ARGV[0],"results1.csv")) do |row|

		tmp = row[0].split("_")[0..1]
		name = tmp[0]+" "+tmp[1]		
		
		if names.has_key?(name) && row[2] == "true"
			names[name][1] = 1
		end

	end

	CSV.foreach(File.join(ARGV[0],"results3.csv")) do |row|

		tmp = row[0].split("_")[0..1]
		name = tmp[0]+" "+tmp[1]		
		
		if names.has_key?(name) && row[2] == "true"
			names[name][2] = 1
		end

	end

	names = names.sort { |a,b| a[0] <=> b[0] }

	CSV.open("results1.csv","w") do |csv|
		names.each do |student|
			csv << student[1] 
		end
	end 
