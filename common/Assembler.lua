-------------------------------------------------------------[Assembler]----------------------------------------------

function MASK_N_BITS(N)

	return Memory(1):SBR(N) + Memory(-1)

end

function POWERPC_OPCODE(value)

	return Memory(value):SBL(26)

end


ForceDebugOutput(false)
--s = "E"

MASK_N_BITS(1)


local v = Memory("38A00000"):OR(string.byte("G")):GetPTRHEX()
Message(POWERPC_OPCODE(14).ptr)

