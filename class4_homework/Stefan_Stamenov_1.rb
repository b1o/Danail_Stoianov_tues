require 'csv'

h={}

CSV.foreach(File.join(ARGV[0],"Evaluation 2013-2014 - Sheet2.csv")) do |row|
	  name=row[1].to_s+" "+row[2].to_s
		row[3]=name	if row[3].nil?
	  h[row[3]]=[name,0,0]
	end
end


CSV.foreach(File.join(ARGV[0],"results1.csv")) do |row|
	names = row[0].to_s.split("_")[0..1]
	name = names[0].to_s + " " + names[1].to_s
	if h.has_key?(name)
	  h[name][1]=row [2]=='true' ? 1 : 0
	end
end

CSV.foreach(File.join(ARGV[0],"results3.csv")) do |row|
	names = row[0].to_s.split("_")[0..1]
	name = names[0].to_s + " " + names[1].to_s
	if h.has_key?(name)
	  h[name][2]=row [2]=='true' ? 1 : 0
	end
end

h = h.sort {|a,b| a[0] <=> b[0] }

CSV.open("results1.csv", "w") do |csv|
	h.each do |std|
	csv<<std[1]
	end
end
