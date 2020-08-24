/**
 * Copyright 2020 Outfrost
 * This work is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE.WTFPL file for more details.
 */

﻿using TMPro;
using UnityEngine;

namespace Outfrost.Debug {
	
	public class VersionText : MonoBehaviour {
		
		void Start () {
			GetComponent<TextMeshProUGUI>().SetText(Application.productName
			                                        + " "
			                                        + Application.version
			                                        + (Application.buildGUID != ""
					                                        ? ", build " + Application.buildGUID
					                                        : ""));
		}
		
	}
	
}
