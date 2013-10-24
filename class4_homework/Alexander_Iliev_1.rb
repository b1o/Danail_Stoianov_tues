require 'csv'
	names = Hash.new("")
	CSV.foreach(File.join(ARGV[0], "Evaluation 2013-2014 - Sheet2.csv")) do |row|
		if row[0].to_s.length != 1
			next
		else
				name = row[1].strip + " " + row[2].strip
				if row[3] == nil
					row[3] = name 
				end
				names[row[3]] = [name,0,0]
		end
	end
	CSV.foreach(File.join(ARGV[0], "results1.csv")) do |row|
		t = row[0].split("_")[0..1]
		name = t[0] + " " + t[1]
		if names.has_key?(name) && row[2] == "true"
			names[name][1] = 1
		elsif names.has_key?(name) && row[2] == "false"
			names[name][1] = 0
		end
	end
	CSV.foreach(File.join(ARGV[0], "results3.csv")) do |row|
		t = row[0].split("_")[0..1]
		name = t[0] + " " + t[1]
		if names.has_key?(name) && row[2] == "true"
			names[name][2] = 1
		elsif names.has_key?(name) && row[2] == "false"
			names[name][2] = 0
		end
	end
	all = []
	names.each do |row|
		all << row[1]
	end
	all.sort!{|a,b| a[0] <=> b[0] }
CSV.open("results1.csv", "w") do |csv|
  all.each do |element|
  	csv << element
  end
end
