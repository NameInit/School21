import sys

def email_to_name(email):
    username = email.split('@')[0]
    parts = username.split('.')
    if len(parts) == 2:
        first_name, last_name = parts
        return first_name.capitalize(), last_name.capitalize()
    else:
        return username.capitalize(), ''

def main():
    if len(sys.argv) != 2:
        print("need filename arg")
        return
    
    input_file = sys.argv[1]
    output_file = "employees.tsv"
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        outfile.write("Name\tSurname\tE-mail\n")
        
        for line in infile:
            email = line.strip()
            if not email:
                continue
            first_name, last_name = email_to_name(email)
            outfile.write(f"{first_name}\t{last_name}\t{email}\n")

if __name__ == "__main__":
    main()