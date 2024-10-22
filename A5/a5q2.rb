class Inventory
    attr_reader :manufacturer
    attr_reader :category
    attr_reader :modelNum
    @@total=0
    @@array = Array.new

    def self.all_instances
        @@array
    end

    #constructor
    def initialize(category, batteryLife, modelNum, color, manufacturer, status, yearBuilt, price, features)
        @@total +=1
        @category = category
        @batteryLife = batteryLife
        @modelNum = modelNum
        @color = color
        @manufacturer = manufacturer
        @status = status
        @yearBuilt = yearBuilt 
        @price =price
        @features = features
        @@array << self
    end 
    
    #accessor for each attribute
    def printItem
        print @category,", "
        print @batteryLife,", "
        print @modelNum,", "
        print @color,", "
        print @manufacturer,", "
        print @status,", "
        print @yearBuilt,", "
        print @price,", "
        print @features
    end 
    
    def toString
      myInv = @category.to_s + ", " + @batteryLife.to_s + ", " + @modelNum.to_s + ", " + @color.to_s + ", " + @manufacturer.to_s + ", " + @status.to_s + ", "+ @yearBuilt.to_s + ", " + @price.to_s + ", " + @features.to_s
      return myInv
    end 
end

def showInventory()
    arrInventory = Inventory.all_instances
    arrInventory.each { |x| puts x.printItem }
    if arrInventory.empty?
      puts "Inventory is empty"
    end
end

def addToInventory(invStr)
    if invStr.length==1
      return 
    end
    puts invStr
    # invStr = invStr.downcase
    status = invStr.scan(/(used|new|refurbished)/i)
    # puts status
    # puts invStr
    invStr = invStr.gsub(/(used|new|refurbished)/i,"")
    # puts invStr
    features = invStr.scan(/{(.*?)\}/)
    invStr = invStr.gsub(/{(.*?)\}/,"")
    price = invStr.scan(/\d+\$/)
    invStr = invStr.gsub(/\d+\$/,"")
    # yearBuilt = invStr.scan(/\d\d\d\d/)[0].chop()
    batteryLife = invStr.scan(/\d+hrs/)
    invStr = invStr.gsub(/\d+hrs/,"")
    color = invStr.scan(/(silver|white|white|black|burgundy|blue)/)
    invStr = invStr.gsub(/(silver|white|white|black|burgundy|blue)/,"")
    
    manufacturer = invStr.scan(/(apple|samsung|google|lenovo|lg)/i)
    invStr = invStr.gsub(/(apple|samsung|google|lenovo|lg)/i,"")
    category = invStr.scan(/(smartphone|tablet|laptop|smartwatch)/i)
    invStr = invStr.gsub(/(smartphone|tablet|laptop|smartwatch)/i,"")
    modelNum = invStr.scan(/[a-zA-Z\d]{5,}+/)
    invStr = invStr.gsub(/[a-zA-Z\d]{5,}+/,"")
    yearBuilt = invStr.scan(/\d\d\d\d/)

    manufacturer = manufacturer.join(" ")
    if manufacturer.downcase == "lg"
      manufacturer = manufacturer.upcase
    else
      manufacturer = manufacturer.downcase
      manufacturer = manufacturer.capitalize
    end
    # puts invStr
    return Inventory.new(category[0].join(" ").downcase.capitalize, batteryLife.join(" "), modelNum.join(" "), color.join(" ").downcase, manufacturer, status.join(" ").downcase, yearBuilt.join(" "), price.join(" "), "{"+features.join(" ")+"}")
end

def importListing()
    fname="inventory.txt"
    lines = File.readlines(fname)
    lines.each { |item|
    addToInventory(item)
    }
end

def exportListing()
  out_file = File.new("out.txt", "w")
  
  arrInventory = Inventory.all_instances.sort_by(&:modelNum)
  arrInventory = arrInventory.sort_by(&:category)
  arrInventory = arrInventory.sort_by(&:manufacturer)
  # puts arrInventory[0].toString
  arrInventory.each { |x| out_file.puts x.toString+"\n\n" }
  out_file.close
end

while true
    puts "\nSelect one of the following options: \n 1. show the inventory \n 2. add to inventory \n 3. import a listing \n 4. export to listing \n 5. exit. "
    input = gets.to_i
    case input
    when 1
        puts "\nyou have selected inventory display option\n\n"
        showInventory()
    when 2
        puts "\nyou have selected add to inventory option, please enter the listing\n\n"
        invStr = gets.chomp
        addToInventory(invStr)
    when 3
        puts "\nyou have selected import a list option.\n\n"
        importListing()
    when 4
        puts "\nyou have selected export to list option\n\n"
        exportListing()
    when 5
        puts "\nyou have selected to exit the program\n\n"
        abort ("exiting the program...")
    else 
        puts "\ninvalid input detected\n\n"
    end
end