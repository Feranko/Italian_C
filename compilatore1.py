import sys
import os
import subprocess

def compile_and_run(file_name):
    with open(file_name, "r") as f:
        content = f.read()
        content = content.replace("includi", "#include")
        content = content.replace("intero", "int")
        content = content.replace("galleggiante", "float")
        content = content.replace("doppia", "double")
        content = content.replace("vocabolo", "char")
        content = content.replace("booleana", "bool")
        content = content.replace("vero", "true")
        content = content.replace("falso", "false")
        content = content.replace("per", "for")
        content = content.replace("finche", "while")
        content = content.replace("fai", "do")
        content = content.replace("ritorna", "return")
        content = content.replace("stampa", "printf")
        content = content.replace("principale", "main")

    try:
        os.makedirs("output")
    except:
        pass
    os.chdir("output")

    with open("main.c", "w") as file_di_mezzo:
        file_di_mezzo.write(content)
        file_di_mezzo.close()

    os.system("gcc main.c -o main && rm main.c")
    os.system("./main")



if __name__ == "__main__":
    file_name = input("Inserisci il file: ")
    compile_and_run(file_name)
