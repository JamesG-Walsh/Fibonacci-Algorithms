CC = g++
H = BigInt.h 
CA = asn1_a.cpp BigInt.cpp
CB = asn1_b.cpp BigInt.cpp
CPPC = asn1_c.cpp BigInt.cpp
EXECA = asn1_a
EXECB = asn1_b
EXECC = asn1_c

build: ${C} ${H}
	${CC} ${CA} -o ${EXECA}
	${CC} ${CB} -o ${EXECB}
	${CC} ${CPPC} -o ${EXECC}

clean:
	@echo "Cleaning up..."
	rm ${EXECA} ${EXECB} ${EXECC} *.o -v -f

make asn1_a:
	${CC} ${CA} -o ${EXECA}

make asn1_b:
	${CC} ${CB} -o ${EXECB}

make asn1_c:
	${CC} ${CPPC} -o ${EXECC}

testA:
	./${EXECA}

testB:
	./${EXECB}

testC:
	./${EXECC}

runA:
	make clean
	make
	make testA

runB:
	make clean
	make
	make testB

runC:
	make clean
	make
	make testC