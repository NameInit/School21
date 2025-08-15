num_of_steps = 5

report_template = """Report

We have made {total} observations from tossing a coin: {tails} of them were tails and {heads} of
them were heads. The probabilities are {tail_fraction:.2f}% and {head_fraction:.2f}%, respectively. Our
forecast is that in the next {steps} observations we will have: {predictions_t} tail and {predictions_h} heads.
"""