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
