import numpy as np
import sys

def splitArray(a, n):
    k = len(a) - n
    for i in range(0, n, 1):
        while k < len(a):
            return a[k:k + n]
        k += n
        
def sysEq(resultMtx):
    rows = len(resultMtx)
    columns = len(resultMtx[0])

    i = 0
    j = 0
    #converted string of index 
    convInd = ""
    stringMtx = [""] * rows
    #stringMtx.append([0] * columns)
    #cX1 + cX2 + cX3 
    #array to hold each rows equation 
    sysEq = [""] * rows
    #make array multidimensional
    #sysEq.append([0] * columns)
    lines = [""] * rows

    equations = [""]
    

    for i in range(rows):
        for j in range(columns):
            #convert index value into a string
            convInd = str(j+1)
            #combine constant and index 
            #append to array 
            xVar = "X" + convInd
            stringMtx[j] = (str(resultMtx[i][j]))
            stringMtx[j] = stringMtx[j] + "(" + xVar + ")"
            sysEq.append(stringMtx[j])
        
        sysEq.remove("")
        lines = splitArray(sysEq, rows)
        add = "+"
        add = add.join(lines)
        equations.append(add)
                
    equations.remove("")
    for m in range(rows):
        print("A = " + equations[m] + "\n")
        print("---------------------------")

def readMatrix(filename): 
    resultMatrix = []

    #open text file 
    #name matrixFile
    matrixFile = open(filename, 'r')

    for lines in matrixFile: 
        #split matrixFile by line
        lines = lines.rstrip('\n')

        #then split by comma 
        sCells = lines.split(',')

        #using numpy map, change strings to float 
        fCells = list(map(np.float32, sCells))

        #append to resultMatrix 
        resultMatrix.append(fCells)

    matrixFile.close()
    
    #find matrix dimensions 
    rows = len(resultMatrix)
    columns = len(resultMatrix[0])

    #print(filename)
    #print("--------------\n")
    #print("[" ,rows, "x ", columns, "] matrix")
    #print("--------------\n")

    sysEq(resultMatrix)

    return np.asarray(resultMatrix, dtype=np.float32)



    

def main(): 
    print("--------------\n")
    readMatrix("mat1-1.txt")
    #readMatrix("mat2-1.txt")
    #readMatrix("mat3-1.txt")
    #readMatrix("mat4-1.txt")


if __name__ == '__main__':
    main()