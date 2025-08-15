import config
import sys
from analytics import Research


def main():
	if len(sys.argv)!=2:
		print("Error args!!!")
		sys.exit(1)
	
	r = Research(sys.argv[1])
	data = r.file_reader()
	calc=r.Calculations(data)
	total = len(data)
	tails = calc.counts()[0]
	heads = calc.counts()[1]
	tail_fraction = calc.fractions()[0]
	head_fraction = calc.fractions()[1]
	steps=config.num_of_steps
	analyze = r.Analytics
	pred=analyze.predict_random(steps)
	calc2=r.Calculations(pred)
	predictions = calc2.counts()
	if len(predictions)==1:
		predictions.append(0)
	report = config.report_template.format(
		total = total,
		tails = tails,
		heads=heads,
		tail_fraction=tail_fraction,
		head_fraction=head_fraction,
		steps=steps,
		predictions_t=predictions[0],
		predictions_h=predictions[1]
	)
	analyze.save_file(report, "report", "txt")
	r.send_message(report)

if __name__ == "__main__":
    main()