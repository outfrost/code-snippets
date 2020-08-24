/**
 * Copyright 2020 Outfrost
 * This work is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE.WTFPL file for more details.
 */

﻿using System;
using System.Collections.Generic;
using UnityEngine;

namespace Outfrost {
	
	public class InputDispatcher : MonoBehaviour {
		
		public delegate void KeyDownHandler(KeyCode keyCode);
		
		private readonly Dictionary<KeyCode, LinkedList<KeyDownHandler>> keyDownHandlers = new Dictionary<KeyCode, LinkedList<KeyDownHandler>>();
		
		private void Update() {
			// Scan registered key inputs and invoke handlers
			foreach (var entry in keyDownHandlers) {
				if (Input.GetKeyDown(entry.Key)) {
					foreach (KeyDownHandler handler in entry.Value) {
						handler(entry.Key);
					}
				}
			}
		}
		
		public void AddKeyDownHandler(KeyCode keyCode, KeyDownHandler handler) {
			LinkedList<KeyDownHandler> list;
			try {
				list = new LinkedList<KeyDownHandler>();
				keyDownHandlers.Add(keyCode, list);
			}
			catch (ArgumentException) {
				list = keyDownHandlers[keyCode];
			}
			
			list.AddLast(handler);
		}
		
	}
	
}
