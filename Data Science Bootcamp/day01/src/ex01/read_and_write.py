def main():
	input = "ds.csv"
	output = "ds.tsv"

	with open(input, 'r', encoding="utf-8") as csv_file:
		with open(output, 'w', encoding="utf-8") as tsv_file:
			for line in csv_file.readlines():
				data_line=line.strip().split(',')
				data_line=data_line[:2]+[''.join(data_line[2:len(data_line)-2])]+data_line[len(data_line)-2:]
				new_line='\t'.join(data_line)
				tsv_file.write(new_line+'\n')
	return


if __name__ == '__main__':
	main()