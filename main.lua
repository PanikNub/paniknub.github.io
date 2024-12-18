-- Functions --
local function sleep(seconds)
	os.execute("sleep " .. tonumber(seconds))
end

local function G(char, amount)
	for i = 1, amount do
		io.write(char)
	end
end
local function header(text)
	G("-", 50) ; G("\n", 1)
	print("-- ".. text.. " --")
	G("-", 50) ; G("\n", 1)
end
local function line()
	G("-", 30)
	G("\n", 1)
end

-- Main --
header("PanikHub")
print("Type in HELP for a list of commands!\n")

while true do
	io.write("Select > ")
	local Select = io.read()
	Select = string.upper(Select)
	
	-- Peza! --
	if Select == "PEZA" then
		print("")
		header("Peza!")
		print("Type in HELP for a list of commands!\n")

		while true do
			io.write("Action > ")
			action = io.read()
			action = string.upper(action)

			if action == "EXIT" then
				print("Exitting Peza!...")
				sleep(1)
				break
			end
			line()
		end
	-- Exit --
	elseif Select == "EXIT" then
		print("Exitting PanikHub...")
		sleep(1)
		os.exit()
	end
	line()
end
