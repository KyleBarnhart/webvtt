#include "cue_testfixture"
class CueTimes : public CueTest { };

/**
 * 'From' timestamp'
 */

/**
 * Bounds checking - 'from' hour
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'hours' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 4. If the character indicated by position is not an ASCII digit, then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromHourBeyondLowBoundary)
{
  loadVtt( "cue-times/from/hour-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'hours' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 4. If the character indicated by position is not an ASCII digit, then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromHourBeyondHighBoundary)
{
  loadVtt( "cue-times/from/hour-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'hours' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromHourWithinLowBoundary)
{
  loadVtt( "cue-times/from/hour-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 56, 5  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'hours' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromHourWithinHighBoundary)
{
  loadVtt( "cue-times/from/hour-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 9, 56, 5  );
}

/**
 * Bounds checking - 'from' minute
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'minutes' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMinuteBeyondLowBoundary)
{
  loadVtt( "cue-times/from/minute-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'minutes' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMinuteBeyondHighBoundary)
{
  loadVtt( "cue-times/from/minute-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'minutes' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromMinuteWithinLowBoundary)
{
  loadVtt( "cue-times/from/minute-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 0, 56, 5  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'minutes' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromMinuteWithinHighBoundary)
{
  loadVtt( "cue-times/from/minute-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 56, 005 );
}

/**
 * Bounds checking - 'from' second
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'seconds' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromSecondBeyondLowBoundary)
{
  loadVtt( "cue-times/from/second-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'seconds' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromSecondBeyondHighBoundary)
{
  loadVtt( "cue-times/from/second-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'seconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromSecondWithinLowBoundary)
{
  loadVtt( "cue-times/from/second-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 0, 5  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'seconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromSecondWithinHighBoundary)
{
  loadVtt( "cue-times/from/second-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 59, 5 );
}

/**
 * Bounds checking - 'from' millisecond
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'milliseconds' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMillisecondBeyondLowBoundary)
{
  loadVtt( "cue-times/from/millisecond-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'milliseconds' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMillisecondBeyondHighBoundary)
{
  loadVtt( "cue-times/from/millisecond-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'milliseconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromMillisecondWithinLowBoundary)
{
  loadVtt( "cue-times/from/millisecond-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 56, 0  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'milliseconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromMillisecondWithinHighBoundary)
{
  loadVtt( "cue-times/from/millisecond-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 9, 56, 999 );
}

/**
 * Format - 'from' numbers of minute digits
 */

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'minutes' component
 * consists of one digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromOneDigitMinute)
{
  loadVtt( "cue-times/from/minute-1-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'minutes' component
 * consists of two digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromTwoDigitMinute)
{
  loadVtt( "cue-times/from/minute-2-digit.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 0, 1, 0, 0 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'minutes' component
 * consists of three (or more) digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromThreeDigitMinute)
{
  loadVtt( "cue-times/from/minute-3-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Format - 'from' numbers of seconds digits
 */
/**
 * Test expecting parser to report an error when a 4 component timestamp's 'seconds' component
 * consists of a single digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromOneDigitSecond)
{
  loadVtt( "cue-times/from/second-1-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'seconds' component
 * consists of two digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromTwoDigitSecond)
{
  loadVtt( "cue-times/from/second-2-digit.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 0, 0, 25, 0 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'seconds' component
 * consists of three (or more) digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromThreeDigitSecond)
{
  loadVtt( "cue-times/from/second-3-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Format - 'from' numbers of milliseconds digits
 */
/**
 * Test expecting parser to report an error when a 4 component timestamp's 'milliseconds' component
 * consists of fewer than three digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromTwoDigitMillisecond)
{
  loadVtt( "cue-times/from/millisecond-2-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'milliseconds' component
 * consists of three digits between the range of allowed values (000-999)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, FromThreeDigitMillisecond)
{
  loadVtt( "cue-times/from/millisecond-3-digit.vtt", 1 );
  assertEquals( getCue( 0 ).startTime(), 0, 0, 0, 111 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'milliseconds' component
 * consists of more than three digits between the range of allowed values (000-999)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromFourDigitMillisecond)
{
  loadVtt( "cue-times/from/millisecond-4-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Range checking
 */
/**
 * Test expecting parser to fail when a 4 component timestamp's 'minutes' component
 * consists of a value greater than 59
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMinuteGreaterThan59)
{
  loadVtt( "cue-times/from/minute-greater-than-59.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'seconds' component
 * consists of a value greater than 59
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromSecondGreaterThan59)
{
  loadVtt( "cue-times/from/second-greater-than-59.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'milliseconds' component
 * consists of a value greater than 999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromMillisecondGreaterThan999)
{
  loadVtt( "cue-times/from/millisecond-greater-than-999.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 1 );
}

/**
 * Bad delimiter
 */
/**
 * Test expecting parser to fail when a 4 component timestamp's 'hour' component
 * is separated from the 'minute' component by a character other than U+003A (COLON)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 8. If position is beyond the end of input or if the character at position is not a U+003A COLON character (:), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromBadDelimiterHourMinute)
{
  loadVtt( "cue-times/from/bad-delimiter-hour-minute.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'minute' component
 * is separated from the 'second' component by a character other than U+003A (COLON)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.1. If position is beyond the end of input or if the character at position is not a U+003A COLON character (:), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromBadDelimiterMinuteSecond)
{
  loadVtt( "cue-times/from/bad-delimiter-minute-second.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'second' component
 * is separated from the 'milliseconds' component by a character other than U+002E (FULL STOP)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 13. If position is beyond the end of input or if the character at position is not a U+002E FULL STOP character (.), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, FromBadDelimiterSecondMillisecond)
{
  loadVtt( "cue-times/from/bad-delimiter-second-millisecond.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 1 );
}

/**
 * 'Until' timestamp'
 */

/**
 * Bounds checking - 'until' hour
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'hours' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 4. If the character indicated by position is not an ASCII digit, then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilHourBeyondLowBoundary)
{
  loadVtt( "cue-times/until/hour-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'hours' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 4. If the character indicated by position is not an ASCII digit, then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilHourBeyondHighBoundary)
{
  loadVtt( "cue-times/until/hour-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'hours' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilHourWithinLowBoundary)
{
  loadVtt( "cue-times/until/hour-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 10, 02, 780  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'hours' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilHourWithinHighBoundary)
{
  loadVtt( "cue-times/until/hour-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 9, 10, 02, 780 );
}

/**
 * Bounds checking - 'until' minute
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'minutes' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMinuteBeyondLowBoundary)
{
  loadVtt( "cue-times/until/minute-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'minutes' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMinuteBeyondHighBoundary)
{
  loadVtt( "cue-times/until/minute-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'minutes' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilMinuteWithinLowBoundary)
{
  loadVtt( "cue-times/until/minute-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 1, 2, 780 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'minutes' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilMinuteWithinHighBoundary)
{
  loadVtt( "cue-times/until/minute-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 9, 02, 780 );
}


/**
 * Bounds checking - 'until' second
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'seconds' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilSecondBeyondLowBoundary)
{
  loadVtt( "cue-times/until/second-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'seconds' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilSecondBeyondHighBoundary)
{
  loadVtt( "cue-times/until/second-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'seconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilSecondWithinLowBoundary)
{
  loadVtt( "cue-times/until/second-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 10, 0, 780  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'seconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilSecondWithinHighBoundary)
{
  loadVtt( "cue-times/until/second-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 10, 59, 780 );
}

/**
 * Bounds checking - 'until' millisecond
 */
/**
 * Test expecting parser to report an error and skip cue
 * when a 4 component timestamp's 'milliseconds' component consists
 * of a non-digit character (below U+0030)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMillisecondBeyondLowBoundary)
{
  loadVtt( "cue-times/until/millisecond-beyond-low-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'milliseconds' component consists
 * of a non-digit character (above U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMillisecondBeyondHighBoundary)
{
  loadVtt( "cue-times/until/millisecond-beyond-high-boundary.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'milliseconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilMillisecondWithinLowBoundary)
{
  loadVtt( "cue-times/until/millisecond-within-low-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 10, 02, 000  );
}

/**
 * Test expecting parser to encounter no errors when parsing a valid, well-formed
 * cue timestamp whose 'milliseconds' component's digits are all ASCII digits (U+0030-U+0039)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilMillisecondWithinHighBoundary)
{
  loadVtt( "cue-times/until/millisecond-within-high-boundary.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 10, 02, 999 );
}

/**
 * Format - 'until' numbers of minute digits
 */
/**
 * Test expecting parser to report an error when a 4 component timestamp's 'minutes' component
 * consists of a single digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilOneDigitMinute)
{
  loadVtt( "cue-times/until/minute-1-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'minutes' component
 * consists of two digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilTwoDigitMinute)
{
  loadVtt( "cue-times/until/minute-2-digit.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 0, 2, 0, 0 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'minutes' component
 * consists of three (or more) digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilThreeDigitMinute)
{
  loadVtt( "cue-times/until/minute-3-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Format - 'until' numbers of seconds digits
 */
/**
 * Test expecting parser to report an error when a 4 component timestamp's 'seconds' component
 * consists of a single digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilOneDigitSecond)
{
  loadVtt( "cue-times/until/second-1-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'seconds' component
 * consists of two digit between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilTwoDigitSecond)
{
  loadVtt( "cue-times/until/second-2-digit.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 0, 0, 27, 0 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'seconds' component
 * consists of three (or more) digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.3. If string is not exactly two characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilThreeDigitSecond)
{
  loadVtt( "cue-times/until/second-3-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Format - 'until' numbers of milliseconds digits
 */
/**
 * Test expecting parser to report an error when a 4 component timestamp's 'milliseconds' component
 * consists of fewer than three digits between the range of allowed values (00-59)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilTwoDigitMillisecond)
{
  loadVtt( "cue-times/until/millisecond-2-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to report no error when a 4 component timestamp's 'milliseconds' component
 * consists of three digits between the range of allowed values (000-999)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, UntilThreeDigitMillisecond)
{
  loadVtt( "cue-times/until/millisecond-3-digit.vtt", 1 );
  assertEquals( getCue( 0 ).endTime(), 0, 0, 0, 222 );
}

/**
 * Test expecting parser to report an error when a 4 component timestamp's 'milliseconds' component
 * consists of more than three digits between the range of allowed values (000-999)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes,UntilFourDigitMillisecond)
{
  loadVtt( "cue-times/until/millisecond-4-digit.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Range checking
 */
/**
 * Test expecting parser to fail when a 4 component timestamp's 'minutes' component
 * consists of a value greater than 59
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 10. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMinuteGreaterThan59)
{
  loadVtt( "cue-times/until/minute-greater-than-59.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'seconds' component
 * consists of a value greater than 59
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilSecondGreaterThan59)
{
  loadVtt( "cue-times/until/second-greater-than-59.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'milliseconds' component
 * consists of a value greater than 999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 15. If string is not exactly three characters in length, return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilMillisecondGreaterThan999)
{
  loadVtt( "cue-times/until/millisecond-greater-than-999.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_MALFORMED_TIMESTAMP, 3, 18 );
}

/**
 * Bad delimiter
 */
/**
 * Test expecting parser to fail when a 4 component timestamp's 'hour' component
 * is separated from the 'minute' component by a character other than U+003A (COLON)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 8. If position is beyond the end of input or if the character at position is not a U+003A COLON character (:), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilBadDelimiterHourMinute)
{
  loadVtt( "cue-times/until/bad-delimiter-hour-minute.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'minute' component
 * is separated from the 'second' component by a character other than U+003A (COLON)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.1. If position is beyond the end of input or if the character at position is not a U+003A COLON character (:), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilBadDelimiterMinuteSecond)
{
  loadVtt( "cue-times/until/bad-delimiter-minute-second.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * Test expecting parser to fail when a 4 component timestamp's 'second' component
 * is separated from the 'milliseconds' component by a character other than U+002E (FULL STOP)
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 13. If position is beyond the end of input or if the character at position is not a U+002E FULL STOP character (.), then return an error and abort these steps.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 10. Collect a WebVTT timestamp. If that algorithm fails, then abort these steps and return failure. Otherwise, let cue's text track cue start time be the collected time.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 50. Bad cue: Discard cue.
 */
TEST_F(CueTimes, UntilBadDelimiterSecondMillisecond)
{
  loadVtt( "cue-times/until/bad-delimiter-second-millisecond.vtt", 0 );
  assertEquals( getError( 0 ), WEBVTT_EXPECTED_TIMESTAMP, 3, 18 );
}

/**
 * This tests the bare minimum required for a valid WebVTT file with
 * one cue and no content.
 * 
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 38. Let cue text be the empty string.
 * 41. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 42. If line is the empty string, then jump to the step labeled cue text processing.
 * 47. Cue text processing: Let the text track cue text of cue be cue text, ...
 * 48. Add cue to the text track list of cues output.
 */
TEST_F(CueTimes, BareMinimum)
{
  loadVtt("cue-times/bare_minimum.vtt", 1);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 0, 1, 0 );
  assertEquals( getCue( 0 ).endTime(), 0, 2, 0 );
}

/**
 * This tests the bare minimum required for a valid WebVTT file with
 * one cue and sample content.
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 38. Let cue text be the empty string.
 * 41. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 45. Let cue text be the concatenation of cue text and line.
 * 47. Cue text processing: Let the text track cue text of cue be cue text, ...
 * 48. Add cue to the text track list of cues output.
 */
TEST_F(CueTimes, BareMinimumWithContent)
{
  loadVtt("cue-times/bare_minimum_content.vtt", 1);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 0, 1, 0 );
  assertEquals( getCue( 0 ).endTime(), 0, 2, 0 );
}

/**
 * This tests the highest legal values in a timestamp.
 * This does not included hours, as the highest legal value
 * of an hour would be the highest value of an int (system-dependent)
 *
 * From http://dev.w3.org/html5/webvtt/#parsing (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 38. Let cue text be the empty string.
 * 41. Collect a sequence of characters that are not U+000A LINE FEED (LF) characters. Let line be those characters, if any.
 * 42. If line is the empty string, then jump to the step labeled cue text processing.
 * 47. Cue text processing: Let the text track cue text of cue be cue text, ...
 * 48. Add cue to the text track list of cues output.
 */
TEST_F(CueTimes, HighestValues)
{
  loadVtt("cue-times/highest_values.vtt", 1);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 59, 59, 998 );
  assertEquals( getCue( 0 ).endTime(), 59, 59, 999 );
}

/**
 * This tests the optional hours token in the timestamp
 * 
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12. If most significant units is hours, or if position is not beyond the end of input and the character at position is a U+003A COLON character (:), run these substeps:
 */
TEST_F(CueTimes, Hours)
{
  loadVtt("cue-times/hours.vtt", 1);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 11, 0, 11, 0 );
  assertEquals( getCue( 0 ).endTime(), 11, 0, 13, 0 );
}

/**
 * This tests multiple cues in a vtt file
 * DISABLED as it is returning an error count greater than 0.
 * Will have to debug when I have some time.
 * 
 * From http://dev.w3.org/html5/webvtt/#webvtt-parser-algorithm (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 48. Add cue to the text track list of cues output.
 * 49. Jump to the step labeled cue loop.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. ...
 * 5. Skip whitespace.
 * 6. If the character at position is not a U+002D HYPHEN-MINUS character (-) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 7. If the character at position is not a U+002D HYPHEN-MINUS character (-) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 9. Skip whitespace.
 * 10. Collect a WebVTT timestamp. ...
 */
TEST_F(CueTimes, MultiCues)
{
  loadVtt("cue-times/multicues.vtt", 2);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 5, 11, 0 );
  assertEquals( getCue( 0 ).endTime(), 5, 13, 0 );
  assertEquals( getCue( 1 ).startTime(), 5, 13, 0 );
  assertEquals( getCue( 1 ).endTime(), 5, 15, 0 );
}

/**
 * This tests nested cues.
 * DISABLED as it is returning an error count greater than
 * 0. Will have to debug when I have some time.
 * 
 * From http://dev.w3.org/html5/webvtt/#webvtt-parser-algorithm (01/31/2013):
 * 37. Collect WebVTT cue timings and settings from line, using cue for the results. If that fails, jump to the step labeled bad cue.
 * 48. Add cue to the text track list of cues output.
 * 49. Jump to the step labeled cue loop.
 *
 * From http://dev.w3.org/html5/webvtt/#collect-webvtt-cue-timings-and-settings (01/31/2013):
 * 4. Collect a WebVTT timestamp. ...
 * 5. Skip whitespace.
 * 6. If the character at position is not a U+002D HYPHEN-MINUS character (-) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 7. If the character at position is not a U+002D HYPHEN-MINUS character (-) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 8. If the character at position is not a U+003E GREATER-THAN SIGN character (>) then abort these steps and return failure. Otherwise, move position forwards one character.
 * 9. Skip whitespace.
 * 10. Collect a WebVTT timestamp. ...
 */
TEST_F(CueTimes, NestedCues)
{
  loadVtt("cue-times/nestedcues.vtt", 6);
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 0, 0, 0 );
  assertEquals( getCue( 0 ).endTime(), 1, 24, 0 );
  assertEquals( getCue( 1 ).startTime(), 0, 0, 0 );
  assertEquals( getCue( 1 ).endTime(), 0, 44, 0 );
  assertEquals( getCue( 2 ).startTime(), 0, 44, 0 );
  assertEquals( getCue( 2 ).endTime(), 1, 19, 0 );
  assertEquals( getCue( 3 ).startTime(), 1, 24, 0 );
  assertEquals( getCue( 3 ).endTime(), 5, 0, 0 );
  assertEquals( getCue( 4 ).startTime(), 1, 35, 0 );
  assertEquals( getCue( 4 ).endTime(), 3, 0, 0 );
  assertEquals( getCue( 5 ).startTime(), 3, 0, 0 );
  assertEquals( getCue( 5 ).endTime(), 5, 0, 0 );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the high end of the valid range (99)
 *
 * e.g 99:00:00.000 --> 99:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHours2DigitsHigh)
{
  loadVtt( "cue-times/from/timestamp_hours_2_digits_high_good.vtt", 1 );
  ASSERT_EQ(0, errorCount()) << "This file should contain no errors.";
  ASSERT_EQ(99, getCue(0).startTime().hours());
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the high end of the valid range (99)
 *
 * e.g 99:00:00.000 --> 99:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHours2DigitsHigh)
{
  loadVtt( "cue-times/until/timestamp_hours_2_digits_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 99, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the low end of the valid range (00)
 *
 * e.g 00:00:00.000 --> 00:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHours2DigitsLow)
{
  loadVtt( "cue-times/from/timestamp_hours_2_digits_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).startTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the low end of the valid range (00)
 *
 * e.g 00:00:00.000 --> 00:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHours2DigitsLow)
{
  loadVtt( "cue-times/until/timestamp_hours_2_digits_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the middle of the valid range (54)
 *
 * e.g. 54:00:00.000 --> 54:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHours2DigitsMiddle)
{
  loadVtt( "cue-times/from/timestamp_hours_2_digits_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 54, getCue(0).startTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of 2 digits at the middle of the valid range (54)
 *
 * e.g. 54:00:00.000 --> 54:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHours2DigitsMiddle)
{
  loadVtt( "cue-times/until/timestamp_hours_2_digits_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 54, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the high end of the valid range
 *
 * e.g 9999:00:00.000 --> 9999:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHoursNDigitsHigh)
{
  loadVtt( "cue-times/from/timestamp_hours_n_digits_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 9999, getCue(0).startTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the high end of the valid range
 *
 * e.g 9999:00:00.000 --> 9999:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHoursNDigitsHigh)
{
  loadVtt( "cue-times/until/timestamp_hours_n_digits_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 9999, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the low end of the valid range
 *
 * e.g. 0000:00:00.000 --> 0000:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHoursNDigitsLow)
{
  loadVtt( "cue-times/from/timestamp_hours_n_digits_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 0000, getCue(0).startTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the low end of the valid range
 *
 * e.g. 0000:00:00.000 --> 0000:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHoursNDigitsLow)
{
  loadVtt( "cue-times/until/timestamp_hours_n_digits_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 0000, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the middle of the valid range
 *
 * e.g. 5544:00:00.000 --> 5544:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampHoursNDigitsMiddle)
{
  loadVtt( "cue-times/from/timestamp_hours_n_digits_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 5544, getCue(0).startTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * consists of more than 2 digits at the middle of the valid range
 *
 * e.g. 5544:00:00.000 --> 5544:00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 5. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 6. Interpret string as a base-ten integer. Let value1 be that integer.
 * 7. If string is not exactly two characters in length, or if value1 is greater than 59, let most significant units be hours.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampHoursNDigitsMiddle)
{
  loadVtt( "cue-times/until/timestamp_hours_n_digits_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 5544, getCue(0).endTime().hours() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * and it's delimiter is omitted.
 *
 * e.g. 00:00.000 --> 00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12. If most significant units is hours, or if position is not beyond the end of input and the character at position is a U+003A COLON character (:), run these substeps:
 *     Otherwise (if most significant units is not hours, and either position is beyond the end of input, or the character at position is not a U+003A COLON character (:)), let value3 have the value of value2, then value2 have the value of value1, then let value1 equal zero.
 */
TEST_F(CueTimes, StartTimeStampHoursOmitted)
{
  loadVtt( "cue-times/from/timestamp_hours_omitted_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).startTime(), 0, 0, 0 );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'hours' component
 * and it's delimiter is omitted.
 *
 * e.g. 00:00.000 --> 00:05.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12. If most significant units is hours, or if position is not beyond the end of input and the character at position is a U+003A COLON character (:), run these substeps:
 *     Otherwise (if most significant units is not hours, and either position is beyond the end of input, or the character at position is not a U+003A COLON character (:)), let value3 have the value of value2, then value2 have the value of value1, then let value1 equal zero.
 */
TEST_F(CueTimes, EndTimeStampHoursOmitted)
{
  loadVtt( "cue-times/from/timestamp_hours_omitted_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  assertEquals( getCue( 0 ).endTime(), 0, 5, 0 );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the high end of the valid range
 * e.g. 00:00:00.999 --> 00:00:01.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMilliSecondsHigh)
{
  loadVtt( "cue-times/from/timestamp_milliseconds_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 999, getCue(0).startTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the high end of the valid range
 * e.g. 00:00:00.999 --> 00:00:01.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMilliSecondsHigh)
{
  loadVtt( "cue-times/until/timestamp_milliseconds_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 999, getCue(0).endTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:01.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMilliSecondsLow)
{
  loadVtt( "cue-times/from/timestamp_milliseconds_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 000, getCue(0).startTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:01.000
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMilliSecondsLow)
{
  loadVtt( "cue-times/until/timestamp_milliseconds_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 000, getCue(0).endTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the middle of the valid range
 * e.g. 00:00:00.555 --> 00:00:01.555
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMilliSecondsMiddle)
{
  loadVtt( "cue-times/from/timestamp_milliseconds_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 555, getCue(0).startTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds-frac' component
 * is a 3 digit character at the middle of the valid range
 * e.g. 00:00:00.555 --> 00:00:01.555
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 14. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 16. Interpret string as a base-ten integer. Let value4 be that integer.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMilliSecondsMiddle)
{
  loadVtt( "cue-times/until/timestamp_milliseconds_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 555, getCue(0).endTime().milliseconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the high end of the valid range
 * e.g. 00:59:00.000 --> 00:59:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMinutesHigh)
{
  loadVtt( "cue-times/from/timestamp_minutes_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 59, getCue(0).startTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the high end of the valid range
 * e.g. 00:59:00.000 --> 00:59:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMinutesHigh)
{
  loadVtt( "cue-times/until/timestamp_minutes_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 59, getCue(0).endTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMinutesLow)
{
  loadVtt( "cue-times/from/timestamp_minutes_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).startTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMinutesLow)
{
  loadVtt( "cue-times/until/timestamp_minutes_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).endTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the middle of the valid range
 * e.g. 00:30:00.000 --> 00:30:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampMinutesMiddle)
{
  loadVtt( "cue-times/from/timestamp_minutes_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 30, getCue(0).startTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'minutes' component
 * is a 2 digit character at the middle of the valid range
 * e.g. 00:30:00.000 --> 00:30:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 9. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 11. Interpret string as a base-ten integer. Let value2 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampMinutesMiddle)
{
  loadVtt( "cue-times/until/timestamp_minutes_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 30, getCue(0).endTime().minutes() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the high end of the valid range
 * e.g. 00:00:59.000 --> 00:00:59.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampSecondsHigh)
{
  loadVtt( "cue-times/from/timestamp_seconds_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 59, getCue(0).startTime().seconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the high end of the valid range
 * e.g. 00:00:59.000 --> 00:00:59.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampSecondsHigh)
{
  loadVtt( "cue-times/until/timestamp_seconds_high_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 59, getCue(0).endTime().seconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampSecondsLow)
{
  loadVtt( "cue-times/from/timestamp_seconds_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).startTime().seconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the low end of the valid range
 * e.g. 00:00:00.000 --> 00:00:00.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampSecondsLow)
{
  loadVtt( "cue-times/until/timestamp_seconds_low_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 00, getCue(0).endTime().seconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the middle of the valid range
 * .g. 00:00:30.000 --> 00:00:30.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, StartTimeStampSecondsMiddle)
{
  loadVtt( "cue-times/from/timestamp_seconds_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 30, getCue(0).startTime().seconds() );
}

/**
 * Test expecting parser to succeed when a 4 component timestamp's 'seconds' component
 * is a 2 digit character at the middle of the valid range
 * .g. 00:00:30.000 --> 00:00:30.999
 *
 * From http://dev.w3.org/html5/webvtt/#collect-a-webvtt-timestamp (01/31/2013):
 * 12.2. Collect a sequence of characters that are ASCII digits, and let string be the collected substring.
 * 12.4. Interpret string as a base-ten integer. Let value3 be that integer.
 * 17. If value2 is greater than 59 or if value3 is greater than 59, return an error and abort these steps.
 * 18. Let result be value1×60×60 + value2×60 + value3 + value4∕1000.
 */
TEST_F(CueTimes, EndTimeStampSecondsMiddle)
{
  loadVtt( "cue-times/until/timestamp_seconds_mid_good.vtt", 1 );
  ASSERT_EQ( 0, errorCount() ) << "This file should contain no errors.";
  ASSERT_EQ( 30, getCue(0).endTime().seconds() );
}
