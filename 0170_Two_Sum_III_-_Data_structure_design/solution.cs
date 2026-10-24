using System.Collections.Generic;

public class TwoSum {
	private Dictionary<int, int> elements = new Dictionary<int, int>();
 
	public void add(int number) {
		if (elements.ContainsKey(number)) {
            elements[number]++;
		} else {
			elements.Add(number, 1);
		}
	}
 
	public bool find(int value) {
		foreach (KeyValuePair<int, int> kv in elements) {
			// kv.Key is numver, kv.Value is times
			int target = value - kv.Key;
			if ((elements.ContainsKey(target) && target != kv.Key) ||
				(kv.Value > 1 && target == kv.Key)) 
			{
				return true;
			}
		}
		return false;
	}
}