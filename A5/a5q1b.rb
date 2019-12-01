fname="assignment5q1.txt"
lines = File.readlines(fname)
line_count = lines.size
text = lines.join 
total_characters_nospaces = text.gsub(/\s+/, '').length
word_count = text.split.length
sentence_count = text.split(/\.|\?|!|;/).length 
paragraph_count = text.split(/\n\n/).length 
page_count = ((IO.readlines(fname).size.to_f)/50).ceil()
average_word_Length = (total_characters_nospaces.to_f / word_count).round(3)
average_sentnece_size=word_count.to_f/word_count.size
average_paragraph_size=(paragraph_count.to_f/paragraph_count.size).round(3)
average_paragraphs_per_page=(page_count.to_f/paragraph_count).round(3)
total_bytes_number=text.bytesize().round(3)
character_density=(total_characters_nospaces.to_f/total_bytes_number).round(3)


# puts "#{total_characters_nospaces} characters excluding spaces"
# puts "#{word_count} words"
# puts "#{sentence_count} sentences"
# puts "#{paragraph_count} paragraphs" 
# puts "#{page_count} page(s)" 

puts "#{average_word_Length} average word length(s)" 
puts "#{average_sentnece_size} average sentence size"
puts "#{average_paragraph_size}"
puts "#{average_paragraphs_per_page}"
puts "#{total_bytes_number}"
puts "#{character_density}"