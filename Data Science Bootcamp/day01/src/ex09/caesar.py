import sys

def main():
    if len(sys.argv) != 4:
        raise Exception("Error args, args=[<name_script, \"decode|encode\":str, \"text\":str, shift:int>]")

    action = sys.argv[1]
    text = sys.argv[2]
    
    try:
        shift = int(sys.argv[3])
    except ValueError:
        raise Exception("Error shift")

    if any(ord(char) < 32 or ord(char) > 126 for char in text):
        raise Exception("Error char")

    if action == "decode":
        shift = -shift
    elif action != "encode":
        raise Exception("Only option: decode and encode")

    result = []
    for char in text:
        if 'a' <= char <= 'z':
            new_char = chr(((ord(char) - ord('a') + shift) % 26) + ord('a'))
        elif 'A' <= char <= 'Z':
            new_char = chr(((ord(char) - ord('A') + shift) % 26) + ord('A'))
        else:
            new_char = char
        result.append(new_char)

    print(''.join(result))


if __name__ == "__main__":
    main()