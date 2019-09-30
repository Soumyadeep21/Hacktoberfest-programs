# Get the parts of speech.
print "Please enter a past-tense verb: "
verb = gets.chomp
print "Please enter a noun: "
noun = gets.chomp
print "Please enter a proper noun: "
prop_noun = gets.chomp
print "Please enter a an adverb: "
adv = gets.chomp

# See where to put it.
print "Please enter a file name: "
fn = gets.chomp
handle = open(fn,"w")

# Go.
printf(handle, "%s got a %s and\n%s %s around the block.\n",
        prop_noun, noun, verb, adv)
handle.close
