/**
 * Copyright 2020 Outfrost
 * This work is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE.WTFPL file for more details.
 */

import java.util.Random;

public class BernoulliDistribution {
	
	private double pSuccess;
	private Random r = new Random();
	
	public BernoulliDistribution(double pSuccess) {
		if (pSuccess < 0.0d || pSuccess > 1.0d) {
			throw new IllegalArgumentException("Success probability outside acceptable range");
		}
		this.pSuccess = pSuccess;
	}
	
	public boolean nextBoolean() {
		return r.nextDouble() < pSuccess;
	}
	
}
