CC = g++
H = BigInt.h 
CA = asn1_a.cpp BigInt.cpp
CB = asn1_b.cpp BigInt.cpp
EXECA = asn1_a
EXECB = asn1_b

build: ${C} ${H}
	${CC} ${CA} -o ${EXECA}
	${CC} ${CB} -o ${EXECB}

testA:
	./${EXECA}

testB:
	./${EXECB}

clean:
	@echo "Cleaning up..."
	rm ${EXECA} ${EXECB} *.o -v -f

runA:
	make clean
	make
	make testA

runB:
	make clean
	make
	make testB