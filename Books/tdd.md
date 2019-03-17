---
title: Test Driven Development for embedded C
author: Jammen Grenning
---


# Ch01: Test Driven Development
- The steps of the TDD cycle in the following list are based on Kent Beck’s description in his book Test-Driven Development [Bec02]:
	1. Add a small test.
	2. Run all the tests and see the new one fail, maybe not even compile.
	3. Make the small changes needed to pass the test.
	4. Run all the tests and see the new one pass.
	5. Refactor to remove duplication and improve expressiveness.

- TDD helps get code working in the first place, but the bigger payoff is in the future, where it supports future developers in understanding the code and keeping it working. Code can be (almost) fearlessly changed.

# Ch02: Test-Driving Tools and Conventions
- a test run may silently exit with an OK, silently exit early showing no errors, or crash with a bang.  When you have a silent failing or crashing test, let the test harness help you confirm what is wrong. Sometimes a production code change will cause a previously passing test to fail, or even crash. So, before chasing the crash, make sure you know which test is failing.

- **The Four-Phase Test Pattern**: 
	- The goal of the pattern is to create concise, readable, and well-structured tests.
	-  Setup: Establish the preconditions to the test.
	- Exercise: Do something to the system.
	- Verify: Check the expected outcome.
	- Cleanup: Return the system under test to its initial state after the test

# Ch03: Starting a C Module
- **Write a test list**:
	- It’s helpful to create a test list before developing new functionality. The test list is derived from the requirements. The test list defines your best vision of what it means to be done. 
	- Don't overthink too much about your tests
	- You will think of other tests as you drive the design. Some of the tests will later be split. Some might be combined.
	- The purpose of the list is to help make sure you don’t forget anything. 

- **Don’t Let the Code Get Ahead of the Tests**: I know it’s hard to resist writing code that you know will be needed, but don’t write it yet. Let the code follow the tests. Sticking to this discipline produces comprehensive tests and thoroughly tested production code.

- **Bob Martin’s Three Laws of TDD**
	- Do not write production code unless it is to make a failing unit test pass.
	- Do not write more of a unit test than is sufficient to fail, and build failures are failures.
	- Do not write more production code than is sufficient to pass the one failing unit test.

- **Test-Drive the Interface Before the Internals**:
	- A good interface is critical for a well-designed module. The first few tests drive the interface design. The focus on the interface means that we’re working from the outside of the code being developed to the inside. 
	- The code behind the interface starts with hard-coded return results, so it feels like nothing is being tested. The point is not testing but driving the interface design and getting the simple boundary tests in place

- If we were not practicing TDD, where more tests are to follow, leaving a wrong implementation could (hard-coded) result in a bug. But we are doing TDD and will write the tests that reveal this weakness.
- TDD is structured procrastination. Put off writing the right production code until the tests force us to. Implementation completeness, the ulti- mate objective, is reached only after all the correct tests are in place.
- Make small and focused tests, test one thing at a time. If a test is too big , you won't be able to catch the root cause.

- Watching the test fail is a good sign that your test can detect when the code is broken.

**IMAGE TDD STATE MACHINE** 
