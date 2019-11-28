lines = File.readlines("assignment5q1.txt")
line_count = lines.size
text = lines.join 
total_characters_nospaces = text.gsub(/\s+/, '').length
word_count = text.split.length
sentence_count = text.split(/\.|\?|!|;/).length 
paragraph_count = text.split(/\n\n/).length 
page_count = ((IO.readlines("assignment5q1.txt").size.to_f)/50).ceil()

puts "#{total_characters_nospaces} characters excluding spaces"
puts "#{word_count} words"
puts "#{sentence_count} sentences"
puts "#{paragraph_count} paragraphs" 
puts "#{page_count} page(s)" 