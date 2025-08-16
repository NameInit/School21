import cProfile
import pstats
import financial

profiler = cProfile.Profile()
profiler.enable()

financial.get_financial_data("AAPL", "Total Revenue")

profiler.disable()
stats = pstats.Stats(profiler)
stats.sort_stats('cumulative')
stats.print_stats(5)